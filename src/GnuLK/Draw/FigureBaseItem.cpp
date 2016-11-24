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

#include <GnuLK/Draw/FigureBaseItem_p.h>

GNULK_BEGIN_NAMESPACE


Figure* FigureBaseItem::figure() const {
    GNULK_PUBLIC(const FigureBaseItem);
    return m->figure;
}



FigureBaseItem* FigureBaseItem::parent() const {
    GNULK_PUBLIC(const FigureBaseItem);
    return m->parent;
}


String FigureBaseItem::name() const {
    GNULK_PUBLIC(const FigureBaseItem);
    return m->name;
}


void FigureBaseItem::set_name(const String &name) {
    GNULK_PUBLIC(FigureBaseItem);
    m->name = name;
}


bool FigureBaseItem::visible() const {
    GNULK_PUBLIC(const FigureBaseItem);
    return m->visible;
}


void FigureBaseItem::set_visible(bool visible) {
    GNULK_PUBLIC(FigureBaseItem);
    m->visible = visible;
}


List<FigureBaseItem*>& FigureBaseItem::children() {
    GNULK_PUBLIC(FigureBaseItem);
    return m->children;
}


const List<FigureBaseItem*>& FigureBaseItem::children() const {
    GNULK_PUBLIC(const FigureBaseItem);
    return m->children;
}


FigureBaseItem* FigureBaseItem::child(const String &name) {
    GNULK_PUBLIC(FigureBaseItem);
    for (auto child : m->children) {
        if (child->name() == name) {
            return child;
        } else {
            return child->child(name);
        }
    }
    // not found
    return nullptr;
}


void FigureBaseItem::add(FigureBaseItem *child) {
    GNULK_PUBLIC(FigureBaseItem);
    m->children.push_back(child);
    child->set_parent(this);
}


void FigureBaseItem::remove(FigureBaseItem *child) {
    GNULK_PUBLIC(FigureBaseItem);
    m->children.remove(child);
    child->set_parent(nullptr);
}


void FigureBaseItem::draw(Graphics &gc) {
    GNULK_PUBLIC(FigureBaseItem);
    for (auto child : m->children) {
        if (child->visible()) {
            child->draw(gc);
        }
    }
}


void FigureBaseItem::set_parent(FigureBaseItem *parent) {
    GNULK_PUBLIC(FigureBaseItem);
    if (parent != nullptr) {
        m->figure = parent->figure();
    } else {
        m->figure = nullptr;
    }

    m->parent = parent;
    for (auto child : m->children) {
        child->set_parent(this);
    }
}

GNULK_END_NAMESPACE
