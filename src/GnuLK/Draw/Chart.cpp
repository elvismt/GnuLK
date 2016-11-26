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


void Chart::plot(const Array1D &x, const Array1D &y,
                 const char *style, const String &name)
{
    GNULK_PUBLIC(Chart);
    FigureScale *scale;
    FigureItem *item;

    if (m->scale_list.size() == 0) {
        scale = new XYScale("scale[0][0]");
        m->scale_list.push_back(scale);
        m->figure->add(scale);
    } else {
        scale = m->scale_list.front();
    }

    item = new XYSeries(x, y, style, name);
    m->item_list.push_back(item);
    scale->add(item);
}

GNULK_END_NAMESPACE
