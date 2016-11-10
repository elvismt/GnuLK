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

#ifndef GNULK_DRAW_GRAPHICS_H
#define GNULK_DRAW_GRAPHICS_H

#include <GnuLK/Util/Object.h>
#include <GnuLK/Draw/Point.h>
#include <GnuLK/Draw/Rect.h>
#include <GnuLK/Draw/Color.h>

GNULK_BEGIN_NAMESPACE

// forward declaration
class Canvas;


class GNULK_EXPORT Graphics
    : public Object
{
public:

    Graphics(Canvas *canvas=nullptr);

    inline
    Graphics(Canvas &canvas)
        : Graphics(&canvas) {}


    void new_path();

    void stroke();

    void stroke_preserve();

    void fill();

    void fill_preserve();

    void clip();

    void clip_preserve();

    void set_color(const Color &c);

    void set_width(double w);

    void save();

    void restore();

    void translate(double dx, double dy);

    inline
    void translate(const Point &p) {
        translate(p.x(), p.y());
    }

    void rotate(double a);

    void move_to(double x, double y);

    inline
    void move_to(const Point &p) {
        move_to(p.x(), p.y());
    }

    void line_to(double x, double y);

    inline
    void line_to(const Point &p) {
        line_to(p.x(), p.y());
    }

    void rect(double x, double y, double w, double h);

    inline
    void rect(const Rect &r) {
        rect(r.x(), r.y(), r.width(), r.height());
    }

    void arc(double x, double y, double r, double a1, double a2);

    inline
    void arc(const Point &c, double r, double a1, double a2) {
        arc(c.x(), c.y(), r, a1, a2);
    }

    void circle(double x, double y, double r);

    inline
    void circle(const Point &c, double r) {
        circle(c.x(), c.y(), r);
    }
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_GRAPHICS_H
