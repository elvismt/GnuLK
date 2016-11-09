/*
 * This file is part of GnuLK.
 *
 * Copyright (c) 2016  Elvis M. Teixeira
 *
 * GnuLK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GnuLK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GnuLK.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GNULK_DRAW_COLOR_H
#define GNULK_DRAW_COLOR_H

#include <GnuLK/Util/Global.h>

GNULK_BEGIN_NAMESPACE

class Color
{
private:

    uint32_t m_value;


public:


    enum Value: uint32_t {
        WHITE         = 0xFFFFFFFF,
        RED           = 0xFF0000FF,
        GREEN         = 0x00FF00FF,
        BLUE          = 0x0000FFFF,
        BLACK         = 0x000000FF
    };


    constexpr Color()
        : m_value{BLACK} { }

    inline Color(uint32_t value)
        : m_value{value} { }

    inline Color(int r, int g, int b, int a=255)
        { set(r, g, b, a); }


    inline
    Color& operator= (const Color &that) {
        m_value = that.m_value;
        return *this;
    }

    inline
    Color& operator= (uint32_t value) {
        m_value = value;
        return *this;
    }


    inline
    bool operator== (const Color &that) {
        return m_value == that.m_value;
    }

    inline
    bool operator!= (const Color &that) {
        return m_value != that.m_value;
    }


    uint32_t red() const { return (m_value >> 24) & 0xFF; }

    uint32_t blue() const { return (m_value >> 16) & 0xFF; }

    uint32_t green() const { return (m_value >> 8) & 0xFF; }

    uint32_t alpha() const { return (m_value) & 0xFF; }

    uint32_t value() const { return m_value; }


    double red_f() const { return double(red())/255.0; }

    double green_f() const { return double(green())/255.0; }

    double blue_f() const { return double(blue())/255.0; }

    double alpha_f() const { return double(alpha())/255.0; }


    inline
    void set(int r, int g, int b, int a=255) {
        m_value = ((r & 0xFF) << 24) |
                  ((g & 0xFF) << 16) |
                  ((b & 0xFF) << 8) |
                  (a & 0xFF);
    }
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_COLOR_H
