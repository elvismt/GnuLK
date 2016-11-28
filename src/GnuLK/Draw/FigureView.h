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

#ifndef GNULK_DRAW_FIGUREVIEW_H
#define GNULK_DRAW_FIGUREVIEW_H

#include <GnuLK/Draw/Window.h>
#include <GnuLK/Draw/Figure.h>
#include <GnuLK/Draw/XYScale.h>
#include <GnuLK/Draw/XYSeries.h>

GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT FigureView
    : public Window
{
public:

    FigureView(const String &title="GnuLK",
               int width=600, int height=500);

    Figure* figure() const;

    virtual void mouse_event(const MouseEvent &event);


protected:

    virtual void draw(Graphics &gc);

    FigureView(ObjectPrivate *priv,
               Figure *figure,
               const String &title,
               int width, int height);
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_FIGUREVIEW_H
