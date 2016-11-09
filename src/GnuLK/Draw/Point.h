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

#ifndef GNULK_UTIL_POINT_H
#define GNULK_UTIL_POINT_H

#include <GnuLK/Util/Global.h>
#include <ostream>

GNULK_BEGIN_NAMESPACE

class Point
{
private:

    double m_x;
    double m_y;

public:


    constexpr Point() :
        m_x{0.0}, m_y{0.0} {}

    inline Point(double x, double y)
        : m_x{x}, m_y{y} {}


    double x() const { return m_x; }
    
    void set_x(double x) { m_x = x; }

    double y() const { return m_y; }
    
    void set_y(double y) { m_y = y; }


    Point operator-() const { return Point(-m_x,-m_y); }

    Point operator- (const Point &v) const { return Point(m_x-v.m_x,m_y-v.m_y); }

    Point operator+ (const Point &v) const { return Point(m_x+v.m_x,m_y+v.m_y); }

    double operator* (const Point &v) const { return m_x*v.m_x + m_y*v.m_y; }
};

GNULK_END_NAMESPACE


inline std::ostream&
operator << (std::ostream &os, const GnuLK::Point &p) {
    os << '(' << p.x() << ',' << p.y() << ')';
    return os;
}

#endif // GNULK_UTIL_POINT_H
