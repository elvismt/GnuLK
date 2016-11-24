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

#ifndef GNULK_FIGUREITEM_H
#define GNULK_FIGUREITEM_H

#include <GnuLK/Util/Object.h>
#include <GnuLK/Draw/Rect.h>

GNULK_BEGIN_NAMESPACE
class Figure;
class FigureScale;
class Graphics;
GNULK_END_NAMESPACE


GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT FigureItem
    : public Object
{
public:

    Figure* figure() const;
    FigureScale* scale() const;

    String name() const;
    void set_name(const String &name);

    bool visible() const;
    void set_visible(bool visible);

    virtual Rect figure_rect() const = 0;
    virtual Rect data_rect() const = 0;


protected:

    friend class FigureScale;

    virtual void set_scale(FigureScale *scale);

    virtual void draw(Graphics &gc) = 0;

    FigureItem(ObjectPrivate *priv)
        : Object(priv) {}
};

GNULK_END_NAMESPACE

#endif // GNULK_FIGUREITEM_H
