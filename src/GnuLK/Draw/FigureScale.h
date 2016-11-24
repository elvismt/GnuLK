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

#ifndef GNULK_FIGURESCALE_H
#define GNULK_FIGURESCALE_H

#include <GnuLK/Draw/Graphics.h>

GNULK_BEGIN_NAMESPACE
class Figure;
class FigureItem;
GNULK_END_NAMESPACE


GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT FigureScale
    : public Object
{
public:

    Figure* figure() const;

    String name() const;
    void set_name(const String &name);

    bool visible() const;
    void set_visible(bool visible);

    Rect layout_rect() const;
    void set_layout_rect(const Rect &rect);

    FigureItem* item(const String &name) const;
    List<FigureItem*>& item_list();
    const List<FigureItem*>& item_list() const;

    virtual void add(FigureItem *item);
    inline void add(FigureItem &item) { add(&item); }

    virtual void remove(FigureItem *item);
    inline void remove(FigureItem &item) { add(&item); }
    inline void remove(const String &name) { add(item(name)); }

    virtual Rect figure_rect() const = 0;
    virtual Rect data_rect() const = 0;

    virtual Point map(const Point &p) const = 0;
    virtual Point unmap(const Point &p) const = 0;

    virtual void rescale() = 0;


protected:

    friend class Figure;

    virtual void set_figure(Figure *figure);

    virtual void draw(const Rect &rect, Graphics &gc);

    FigureScale(ObjectPrivate *priv)
        : Object(priv) {}
};

GNULK_END_NAMESPACE

#endif // GNULK_FIGURESCALE_H
