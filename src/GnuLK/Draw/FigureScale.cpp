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

Figure* FigureScale::figure() const {
    GNULK_PUBLIC(const FigureScale);
    return m->figure;
}


String FigureScale::name() const {
    GNULK_PUBLIC(const FigureScale);
    return m->name;
}


void FigureScale::set_name(const String &name) {
    GNULK_PUBLIC(FigureScale);
    m->name = name;
}


bool FigureScale::visible() const {
    GNULK_PUBLIC(const FigureScale);
    return m->visible;
}


void FigureScale::set_visible(bool visible) {
    GNULK_PUBLIC(FigureScale);
    m->visible = visible;
}


Rect FigureScale::layout_rect() const {
    GNULK_PUBLIC(const FigureScale);
    return m->layout_rect;
}


void FigureScale::set_layout_rect(const Rect &rect) {
    GNULK_PUBLIC(FigureScale);
    m->layout_rect = rect;
}


FigureItem* FigureScale::item(const String &name) const {
    // TODO
}


List<FigureItem*>& FigureScale::item_list() {
    GNULK_PUBLIC(FigureScale);
    return m->item_list;
}


const List<FigureItem*>& FigureScale::item_list() const {
    GNULK_PUBLIC(const FigureScale);
    return m->item_list;
}


void FigureScale::add(FigureItem *item) {
    // TODO
}

void FigureScale::remove(FigureItem *item) {
    // TODO
}


void FigureScale::set_figure(Figure *figure) {
    GNULK_PUBLIC(FigureScale);
    m->figure = figure;
    // TODO
}


void FigureScale::draw(const Rect &rect, Graphics &gc) {
    // TODO
}

GNULK_END_NAMESPACE
