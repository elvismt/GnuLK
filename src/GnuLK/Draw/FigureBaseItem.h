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

#ifndef GNULK_FIGUREBASEITEM_H
#define GNULK_FIGUREBASEITEM_H

#include <GnuLK/Util/Object.h>


GNULK_BEGIN_NAMESPACE
class Graphics;
class Figure;
GNULK_END_NAMESPACE


GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT FigureBaseItem : public Object
{
public:

    Figure* figure() const;

    FigureBaseItem* parent() const;

    String name() const;
    void set_name(const String &name);

    bool visible() const;
    void set_visible(bool visible);

    List<FigureBaseItem*>& children();
    const List<FigureBaseItem*>& children() const;
    FigureBaseItem* child(const String &name);

    virtual void add(FigureBaseItem *child);
    inline void add(FigureBaseItem &child) { add(&child); }

    virtual void remove(FigureBaseItem *child);
    inline void remove(FigureBaseItem &child) { remove(&child); }
    inline void remove(const String &name) { remove(child(name)); }

    virtual void draw(Graphics &gc);


protected:

    virtual void set_parent(FigureBaseItem *parent);

    FigureBaseItem(ObjectPrivate *priv)
        : Object(priv) {}
};

GNULK_END_NAMESPACE

#endif // GNULK_FIGUREBASEITEM_H
