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

#ifndef GNULK_XYSERIES_P_H
#define GNULK_XYSERIES_P_H

#include <GnuLK/Draw/XYSeries.h>
#include <GnuLK/Draw/FigureItem_p.h>

GNULK_BEGIN_NAMESPACE

class XYSeriesPrivate
   : public FigureItemPrivate
{
public:

    XYSeriesPrivate(XYSeries *publ)
       : FigureItemPrivate(publ)
       , line_color(Color::BLUE)
       , line_width(2.0)
       , point_stroke_color(Color::BLUE)
       , point_fill_color(Color::RED)
       , point_radius(2.8)
       , point_stroke_width(1.1)
       , point_symbol(XYSeries::CIRCLES)
    { }


    void check_ranges();
    void draw_line(Graphics &gc);
    void draw_circles(Graphics &gc);
    void draw_line_circles(Graphics &gc);


    Color line_color;
    double line_width;

    Color point_stroke_color;
    Color point_fill_color;
    double point_radius;
    double point_stroke_width;
    uint32_t point_symbol;

    Vector<double> x;
    Vector<double> y;
    uint32_t point_count;

    double x_min, x_max;
    double y_min, y_max;
};

GNULK_END_NAMESPACE

#endif // GNULK_XYSERIES_P_H
