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

#include <GnuLK/Draw/Rect.h>
#include <GnuLK/Draw/FigureBaseItem.h>


GNULK_BEGIN_NAMESPACE
class Figure;
GNULK_END_NAMESPACE


GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT FigureScale
    : public FigureBaseItem
{
public:

    Rect layout_rect() const;

    void set_layout_rect(const Rect &layout_rect);

    Rect figure_rect() const;

    virtual void rescale() = 0;


protected:

    friend class Figure;

    virtual void set_figure(Figure *figure);

    void set_position_rect(const Rect &position_rect);

    FigureScale(ObjectPrivate *priv)
        : FigureBaseItem(priv) {}
};

GNULK_END_NAMESPACE

#endif // GNULK_FIGURESCALE_H
