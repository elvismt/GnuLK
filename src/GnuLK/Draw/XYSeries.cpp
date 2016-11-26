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

#include <GnuLK/Draw/XYSeries_p.h>
#include <GnuLK/Draw/FigureScale.h>

GNULK_BEGIN_NAMESPACE

XYSeries::XYSeries(const Array1D &x,
                   const Array1D &y,
                   const char *style,
                   const String &name)
    : XYSeries(new XYSeriesPrivate(this))
{
    GNULK_PUBLIC(XYSeries);
    m->name = name;
    set_data(x, y);
    set_style(style);
}


Rect XYSeries::figure_rect() const {
    // TODO
}


Rect XYSeries::data_rect() const {
    GNULK_PUBLIC(const XYSeries);
    return Rect(m->x_min, m->y_min,
                m->x_max - m->x_min,
                m->y_max - m->y_min);
}


void XYSeries::set_data(const Array1D &x,
                        const Array1D &y)
{
    GNULK_PUBLIC(XYSeries);

    m->point_count = std::min(x.size(), y.size());
    m->x = x;
    m->y = y;
    m->check_ranges();
}


void XYSeries::draw(Graphics &gc) {
    GNULK_PUBLIC(XYSeries);

    if (m->point_symbol == LINE) {
        m->draw_line(gc);
    } else {
        m->draw_circles(gc);
    }
}


void XYSeriesPrivate::draw_line(Graphics &gc) {
    Point p1 = scale->map(Point(x[0], y[0]));
    gc.new_path();
    gc.move_to(p1);

    gc.set_width(line_width);
    for (uint32_t k=1; k<point_count; ++k) {
        Point p2 = scale->map(Point(x[k], y[k]));
        gc.line_to(p2);
    }

    gc.set_color(line_color);
    gc.stroke();
}


void XYSeriesPrivate::draw_circles(Graphics &gc) {

    gc.set_width(point_stroke_width);
    for (uint32_t k=0; k<point_count; ++k) {
        Point p = scale->map(Point(x[k], y[k]));
        gc.draw_circle(p.x(), p.y(), point_radius,
                       point_fill_color, point_stroke_color);
    }
}


void XYSeriesPrivate::draw_line_circles(Graphics &gc) {
    Point p1 = scale->map(Point(x[0], y[0]));
    Point p2;

    for (uint32_t k=1; k<point_count; ++k) {
        p2 = scale->map(Point(x[k], y[k]));
        gc.set_width(line_width);
        gc.draw_line(p1, p2, line_color);
        gc.set_width(point_stroke_width);
        gc.draw_circle(p1.x(), p1.y(), point_radius,
                       point_fill_color, point_stroke_color);
        p1 = p2;
    }

    gc.draw_circle(p2.x(), p2.y(), point_radius,
                   point_fill_color, point_stroke_color);
}


void XYSeriesPrivate::check_ranges() {
    if (point_count == 0) {
        return;
    }

    x_min = x_max = x[0];
    y_min = y_max = y[0];

    for (uint32_t k=1; k<point_count; ++k) {
        if (x[k] < x_min) x_min = x[k];
        if (x[k] > x_max) x_max = x[k];
        if (y[k] < y_min) y_min = y[k];
        if (y[k] > y_max) y_max = y[k];
    }
}


static inline
uint32_t parse_color(char c) {
    switch (c) {
        case 'k': return Color::BLACK;
        case 'w': return Color::WHITE;
        case 'r': return Color::RED;
        case 'g': return Color::GREEN;
        case 'b': return Color::BLUE;
    }
    return Color::BLUE;
}


static inline
uint32_t parse_symbol(char c) {
    switch (c) {
        case 'o': return XYSeries::CIRCLES;
        case '-': return XYSeries::LINE;
    }
    return XYSeries::CIRCLES;
}


void XYSeries::set_style(const char *style) {
    GNULK_PUBLIC(XYSeries);
    Color stroke_color(Color::BLUE);
    Color fill_color(Color::RED);
    uint32_t symbol = CIRCLES;
    int k = 0;

    if (style != nullptr) {
        if (style[k] != '\0') {
            fill_color = parse_color(style[k++]);
            stroke_color = fill_color;
        }

        if (style[k] != '\0') {
            symbol = parse_symbol(style[k++]);
        }

        if (style[k] != '\0') {
            fill_color = parse_color(style[k++]);
        }
    }

    m->line_color = stroke_color;
    m->point_stroke_color = stroke_color;
    m->point_fill_color = fill_color;
    m->point_symbol = symbol;
}

GNULK_END_NAMESPACE
