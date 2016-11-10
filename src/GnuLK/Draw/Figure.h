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

#ifndef GNULK_DRAW_FIGURE_H
#define GNULK_DRAW_FIGURE_H

#include <GnuLK/Util/Object.h>
#include <GnuLK/Draw/Graphics.h>

GNULK_BEGIN_NAMESPACE

// forward declaration
class FigureScale;


class GNULK_EXPORT Figure
    : public Object
{
public:

    Figure(const String &title);


    List<FigureScale*>& scales();

    const List<FigureScale*>& scales() const;

    FigureScale* scale(const String &title);


    virtual void append(FigureScale *scale);

    inline void append(FigureScale &scale) {
        append(&scale);
    }


    virtual void detach(FigureScale *scale);

    inline void detach(FigureScale &scale) {
        detach(&scale);
    }

    inline void detach(const String &title) {
        detach(scale(title));
    }


    virtual void draw(const Rect &rect, Graphics &gc);



protected:

    Figure(ObjectPrivate *priv)
        : Object(priv)
    { }
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_FIGURE_H
