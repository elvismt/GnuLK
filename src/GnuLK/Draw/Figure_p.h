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

#ifndef GNULK_DRAW_FIGURE_P_H
#define GNULK_DRAW_FIGURE_P_H

#include <GnuLK/Draw/Figure.h>

GNULK_BEGIN_NAMESPACE

class FigurePrivate
    : public ObjectPrivate
{
public:

    FigurePrivate(Figure *publ)
        : ObjectPrivate(publ)
        , name("Figure")
        , back_color(Color::WHITE)
    { }

    void update_layout();


    String name;
    Color back_color;
    double layout_rows;
    double layout_cols;
    List<FigureScale*> scale_list;
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_FIGURE_P_H
