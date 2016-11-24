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

#include <GnuLK/Draw/FigureScale_p.h>

GNULK_BEGIN_NAMESPACE

Rect FigureScale::layout_rect() const {
    GNULK_PUBLIC(const FigureScale);
    return m->layout_rect;
}


void FigureScale::set_layout_rect(const Rect &layout_rect) {
    GNULK_PUBLIC(FigureScale);
    m->layout_rect = layout_rect;
}


Rect FigureScale::figure_rect() const {
    GNULK_PUBLIC(const FigureScale);
    return m->position_rect;
}


void FigureScale::set_figure(Figure *figure) {
    GNULK_PUBLIC(FigureScale);
    m->figure = figure;
    for (auto child : m->children) {
        child->set_parent(this);
    }
}


void FigureScale::set_position_rect(const Rect &position_rect) {
    GNULK_PUBLIC(FigureScale);
    m->position_rect = position_rect;
}

GNULK_END_NAMESPACE
