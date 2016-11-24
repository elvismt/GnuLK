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

#include <GnuLK/Draw/XYScale_p.h>
#include <GnuLK/Draw/FigureItem.h>

GNULK_BEGIN_NAMESPACE

XYScale::XYScale(const String &name)
    : XYScale(new XYScalePrivate(this))
{
    GNULK_PUBLIC(XYScale);
    m->name = name;
}


Rect XYScale::figure_rect() const {
    GNULK_PUBLIC(const XYScale);
    return Rect(m->fig_x_min, m->fig_y_min,
                m->fig_width, m->fig_height);
}


Rect XYScale::data_rect() const {
    GNULK_PUBLIC(const XYScale);
    return Rect(m->dat_x_min, m->dat_y_min,
                m->dat_width, m->dat_height);
}


Point XYScale::map(const Point &p) const {
    GNULK_PUBLIC(const XYScale);
}


Point XYScale::unmap(const Point &p) const {
    GNULK_PUBLIC(const XYScale);
}


void XYScale::rescale() {
    GNULK_PUBLIC(XYScale);
}


void XYScale::draw(const Rect &rect, Graphics &gc) {
    GNULK_PUBLIC(XYScale);

    /* restrict drawing to within the horizontal margin */
    m->fig_x_min = rect.left() + m->left_margin;
    m->fig_x_max = rect.right() - m->right_margin;
    m->fig_width = m->fig_x_max - m->fig_x_min;

    /* restrict drawing to within the vertical margin */
    m->fig_y_min = rect.top() + m->top_margin;
    m->fig_y_max = rect.bottom() - m->bottom_margin;
    m->fig_height = m->fig_y_max - m->fig_y_min;

    gc.save();
    gc.new_path();
    gc.rect(this->figure_rect());
    gc.clip();

    FigureScale::draw(rect, gc);

    gc.restore();
}

GNULK_END_NAMESPACE
