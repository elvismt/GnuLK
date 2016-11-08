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

#ifndef GnuLK_Util_Vec2D_H
#define GnuLK_Util_Vec2D_H

template <class T>
class Vec2D
{
private:

    T m_x;
    T m_y;

public:


    constexpr Vec2D() : m_x{0}, m_y{0} {}

    inline Vec2D(const T &x, const T &y) : m_x{x}, m_y{y} {}


    T x() const { return m_x; }
    void set_x(const T &x) { m_x = x; }

    T y() const { return m_y; }
    void set_y(const T &y) { m_y = y; }
};


typedef Vec2D<double> Point;

#endif // GnuLK_Util_Vec2D_H
