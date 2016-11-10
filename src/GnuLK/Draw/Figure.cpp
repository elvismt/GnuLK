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

#include <GnuLK/Draw/Figure_p.h>

GNULK_BEGIN_NAMESPACE

Figure::Figure(const String &title)
    : Figure(new FigurePrivate(this))
{
    GNULK_PUBLIC(Figure);

    m->title = title;
}


void Figure::append(FigureScale *scale) {
    GNULK_PUBLIC(Figure);
    m->scales.push_back(scale);
}


void Figure::detach(FigureScale *scale) {

}


void Figure::draw(const Rect &rect, Graphics &gc) {
    GNULK_PUBLIC(Figure);

    gc.save();
    gc.new_path();
    gc.rect(rect);
    gc.clip_preserve();

    if (m->back_color.is_null() == false) {
        gc.set_color(m->back_color);
        gc.fill();
    }

    gc.restore();
}

GNULK_END_NAMESPACE
