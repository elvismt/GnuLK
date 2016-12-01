/*
 * Copyright (C) 2016  Elvis Teixeira
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <GnuLK/Draw/Chart_p.h>

GNULK_BEGIN_NAMESPACE

Chart::Chart(const String &title, int width, int height)
    : Chart(new ChartPrivate(this), nullptr, title, width, height)
{ }


XYSeries* Chart::plot(const Array1D &x, const Array1D &y,
                 const char *style, const String &name)
{
    GNULK_PUBLIC(Chart);
    XYScale *scale;
    XYSeries *item;

    if (m->scale_list.size() == 0) {
        scale = static_cast<XYScale*>(m->create_default_scale());
    } else {
        scale = static_cast<XYScale*>(m->scale_list.front());
    }

    item = scale->plot(x, y, style, name);
    m->item_list.push_back(item);
    return item;
}


void Chart::subplots(int rows, int columns) {
    GNULK_PUBLIC(Chart);
    for (int i=0; i<rows; ++i) {
        Vector<FigureScale*> row;
        for (int j=0; j<columns; ++j) {
            XYScale* scale= new XYScale("scale");
            scale->set_layout_rect(Rect(j, i, 1, 1));
            row.push_back(scale);
            m->scale_list.push_back(scale);
            m->figure->add(scale);
        }
        m->scales.push_back(row);
    }
}

XYScale* Chart::operator() (int row, int column) {
    GNULK_PUBLIC(Chart);
    FigureScale *scale;

    if (m->scale_list.size() == 0) {
        scale = m->create_default_scale();
    } else {
        scale = m->scales[row][column];
    }

    return static_cast<XYScale*>(scale);
}


FigureScale* ChartPrivate::create_default_scale() {
    FigureScale *scale = new XYScale("scale[0][0]");
    scale_list.push_back(scale);
    figure->add(scale);

    Vector<FigureScale*> row;
    row.push_back(scale);
    scales.push_back(row);

    return scale;
}

GNULK_END_NAMESPACE
