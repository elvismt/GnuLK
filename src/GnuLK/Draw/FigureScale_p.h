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

#ifndef GNULK_FIGURESCALE_P_H
#define GNULK_FIGURESCALE_P_H

#include <GnuLK/Draw/FigureScale.h>

GNULK_BEGIN_NAMESPACE

class FigureScalePrivate
    : public ObjectPrivate
{
public:

    FigureScalePrivate(FigureScale *publ)
        : ObjectPrivate(publ)
        , figure(nullptr)
        , name("scale")
        , visible(true)
        , layout_rect(0,0,1,1)
        , back_color(Color::BLUE)
    { }


    Figure *figure;
    String name;
    bool visible;
    Rect layout_rect;
    Color back_color;
    List<FigureItem*> item_list;
};

GNULK_END_NAMESPACE

#endif // GNULK_FIGURESCALE_P_H
