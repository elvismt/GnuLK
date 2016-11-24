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
#include <cmath>

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
    Point ret;
    double tmp;

    tmp = (p.x() - m->dat_x_min) / m->dat_width;
    ret.set_x(m->fig_x_min + tmp*m->fig_width);

    tmp = (p.y() - m->dat_y_min) / m->dat_height;
    ret.set_y(m->fig_y_max - tmp*m->fig_height);

    return ret;
}


Point XYScale::unmap(const Point &p) const {
    GNULK_PUBLIC(const XYScale);
    Point ret;
    double tmp;

    tmp = (p.x() - m->fig_x_min) / m->fig_width;
    ret.set_x(m->dat_x_min + tmp*m->dat_width);

    tmp = (m->fig_y_max - p.y()) / m->fig_height;
    ret.set_y(m->dat_y_min + tmp*m->dat_height);

    return ret;
}


void XYScale::rescale() {
    GNULK_PUBLIC(XYScale);

    if (m->item_list.size() == 0) {
        set_x_range(0.0, 1.0);
        set_y_range(0.0, 1.0);
        return;
    }

    auto iter = m->item_list.begin();
    auto end = m->item_list.end();
    FigureItem *item = *iter++;
    Rect item_rect = item->data_rect();

    m->dat_x_min = item_rect.left();
    m->dat_x_max = item_rect.right();
    m->dat_y_min = item_rect.top();
    m->dat_y_max = item_rect.bottom();

    while (iter != end) {
        item = *iter++;
        item_rect = item->data_rect();

        if (item_rect.left() < m->dat_x_min) {
            m->dat_x_min = item_rect.left();
        }
        if (item_rect.right() > m->dat_x_max) {
            m->dat_x_max = item_rect.right();
        }
        if (item_rect.top() < m->dat_y_min) {
            m->dat_y_min = item_rect.top();
        }
        if (item_rect.bottom() > m->dat_y_max) {
            m->dat_y_max = item_rect.bottom();
        }
    }

    m->apply_padding();
}


void XYScalePrivate::apply_padding() {
    dat_width = dat_x_max - dat_x_min;
    double padding = dat_width * x_padding;
    if (dat_width == 0.0) {
        padding = 0.1 * std::fabs(dat_x_max);
        if (padding == 0) {
            padding = 0.1;
        }
    }
    dat_x_min -= padding;
    dat_x_max += padding;
    dat_width += 2.0*padding;

    dat_height = dat_y_max - dat_y_min;
    padding = dat_height * y_padding;
    if (dat_height == 0.0) {
        padding = 0.1 * std::fabs(dat_y_max);
        if (padding == 0) {
            padding = 0.1;
        }
    }
    dat_y_min -= padding;
    dat_y_max += padding;
    dat_height += 2.0*padding;
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

    /* clip to the area defined by the margin */
    gc.save();
    gc.new_path();
    gc.rect(this->figure_rect());
    gc.clip();

    /* let the parent classe's method draw the
     * background and all of the items */
    FigureScale::draw(rect, gc);

    /* return gc in the same state it has entered
     * this method */
    gc.restore();
}


void XYScale::set_x_range(double min, double max) {
    GNULK_PUBLIC(XYScale);
    m->dat_x_min = min;
    m->dat_x_max = max;
    m->dat_width = max - min;
}


void XYScale::set_y_range(double min, double max) {
    GNULK_PUBLIC(XYScale);
    m->dat_y_min = min;
    m->dat_y_max = max;
    m->dat_height = max - min;
}

GNULK_END_NAMESPACE
