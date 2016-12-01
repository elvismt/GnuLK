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

#include <GnuLK/Draw/PlotAxis_p.h>
#include <GnuLK/Draw/FigureScale.h>

GNULK_BEGIN_NAMESPACE

PlotAxis::PlotAxis(const String &name, Orientation orientation,
                   Component component)
    : PlotAxis(new PlotAxisPrivate(this))
{
    GNULK_PUBLIC(PlotAxis);

    m->name = name;
    m->rescalable = false;
    m->orientation = orientation;
    m->component = component;
}


Rect PlotAxis::figure_rect() const {
    // TODO
    return Rect();
}


Rect PlotAxis::data_rect() const {
    // TODO
    return Rect();
}


void PlotAxis::set_range(double min, double max) {
    GNULK_PUBLIC(PlotAxis);
    m->min = min;
    m->max = max;
}


void PlotAxis::set_anchor(double anchor) {
    GNULK_PUBLIC(PlotAxis);
    m->anchor = anchor;
}


void PlotAxis::draw(Graphics &gc) {
    GNULK_PUBLIC(PlotAxis);

    if (m->component & LINE) {
        m->draw_line(gc);
    }
}


void PlotAxisPrivate::draw_line(Graphics &gc) {
    Point p1, p2;

    if (orientation == PlotAxis::HORIZONTAL) {
        p1 = scale->map(Point(min, anchor));
        p2 = scale->map(Point(max, anchor));
    } else {
        p1 = scale->map(Point(anchor, min));
        p2 = scale->map(Point(anchor, max));
    }

    gc.set_antialias(line_antialias);
    gc.set_width(line_width);
    gc.draw_line(p1, p2, line_color);
}

GNULK_END_NAMESPACE
