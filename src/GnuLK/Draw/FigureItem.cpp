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

#include <GnuLK/Draw/FigureItem_p.h>
#include <GnuLK/Draw/FigureScale.h>

GNULK_BEGIN_NAMESPACE

Figure* FigureItem::figure() const {
    GNULK_PUBLIC(const FigureItem);
    return m->figure;
}


FigureScale* FigureItem::scale() const {
    GNULK_PUBLIC(const FigureItem);
    return m->scale;
}


String FigureItem::name() const {
    GNULK_PUBLIC(const FigureItem);
    return m->name;
}


void FigureItem::set_name(const String &name) {
    GNULK_PUBLIC(FigureItem);
    m->name = name;
}


bool FigureItem::visible() const {
    GNULK_PUBLIC(const FigureItem);
    return m->visible;
}


void FigureItem::set_visible(bool visible) {
    GNULK_PUBLIC(FigureItem);
    m->visible = visible;
}


void FigureItem::set_scale(FigureScale *scale) {
    GNULK_PUBLIC(FigureItem);
    Figure *old_figure = m->figure;
    Figure *new_figure = scale ? scale->figure() : nullptr;

    m->scale = scale;
    m->figure = new_figure;
}

GNULK_END_NAMESPACE
