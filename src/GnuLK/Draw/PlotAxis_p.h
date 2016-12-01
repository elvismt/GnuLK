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

#ifndef GNULK_PLOTAXIS_P_H
#define GNULK_PLOTAXIS_P_H

#include <GnuLK/Draw/PlotAxis.h>
#include <GnuLK/Draw/FigureItem_p.h>

GNULK_BEGIN_NAMESPACE

class PlotAxisPrivate
    : public FigureItemPrivate
{
public:


    PlotAxisPrivate(PlotAxis *publ)
        : FigureItemPrivate(publ)
        , component(PlotAxis::EVERITHING)
        , line_antialias(false)
        , line_color(Color::BLACK)
        , line_width(1.0)
    { }


    void draw_line(Graphics &gc);


    PlotAxis::Component component;
    bool line_antialias;
    Color line_color;
    double line_width;

    double min, max;
    double anchor;

    PlotAxis::Orientation orientation;

};

GNULK_END_NAMESPACE

#endif // GNULK_PLOTAXIS_P_H
