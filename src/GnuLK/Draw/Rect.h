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

#ifndef GNULK_UTIL_RECT_H
#define GNULK_UTIL_RECT_H

#include <GnuLK/Draw/Point.h>

GNULK_BEGIN_NAMESPACE

class Rect
{
private:

    double m_x;
    double m_y;
    double m_w;
    double m_h;


public:

    constexpr Rect()
        : m_x{0.0}, m_y{0.0}, m_w{0.0}, m_h{0.0} { }

    inline Rect(double x, double y, double w, double h)
        : m_x{x}, m_y{y}, m_w{w}, m_h{h} { }

    inline Rect(double w, double h)
        : m_x{0.0}, m_y{0.0}, m_w{w}, m_h{h} { }

    inline Rect(const Point &p1, const Point &p2) {
        if (p1.x() < p2.x()) {
            m_x = p1.x();
            m_w = p2.x() - p1.x();
        } else {
            m_x = p2.x();
            m_w = p1.x() - p2.x();
        }
        if (p1.y() < p2.y()) {
            m_y = p1.y();
            m_h = p2.y() - p1.y();
        } else {
            m_y = p2.y();
            m_h = p1.y() - p2.y();
        }
    }


    double x() const { return m_x; }

    void set_x(double x) { m_x = x; }

    double y() const { return m_y; }

    void set_y(double y) { m_y = y; }

    double width() const { return m_w; }

    void set_width(double w) { m_w = w; }

    double height() const { return m_h; }

    void set_height(double h) { m_h = h; }


    Point top_left() const { return Point(m_x,m_y); }

    Point top_right() const { return Point(m_x+m_w,m_y); }

    Point bottom_left() const { return Point(m_x,m_y+m_h); }

    Point bottom_right() const { return Point(m_x+m_w,m_y+m_h); }

    Point center() const { return Point(m_x+m_w/2.0,m_y+m_h/2.0); }


    double top() const { return m_y; }

    double bottom() const { return m_y+m_h; }

    double left() const { return m_x; }

    double right() const { return m_x+m_w; }


    inline
    bool is_empty() const {
        return ! (m_w > 0.0 && m_h > 0.0);
    }


    inline
    bool contains(const Point &p) const {
        if (p.x() < left() || p.x() >= right()) return false;
        if (p.y() <= top() || p.y() > bottom()) return false;
        return true;
    }


    inline
    void translate(double dx, double dy) {
        m_x += dx;
        m_y += dy;
    }

    inline
    void translate(const Point &p) {
        m_x += p.x();
        m_y += p.y();
    }
};

GNULK_END_NAMESPACE


inline std::ostream&
operator << (std::ostream &os, const GnuLK::Rect &r) {
    os << "Rect((" << r.x() << ',' << r.y() << "), "
       << r.width() << 'x' << r.height() << ')';
    return os;
}

#endif // GNULK_UTIL_RECT_H
