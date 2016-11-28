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

#ifndef GNULK_UTIL_WINDOW_H
#define GNULK_UTIL_WINDOW_H

#include <GnuLK/Draw/Graphics.h>
#include <GnuLK/Draw/MouseEvent.h>

GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT Window
    : public Object
{
public:

    Window(const String &title="GnuLK",
           int width=600, int height=500);


    Rect rect() const;

    void redraw();


    virtual void show();

    virtual void hide();

    static void run();

    virtual void draw(Graphics &gc);

    virtual void mouse_event(const MouseEvent &event);


protected:

    Window(ObjectPrivate *priv,
           const String &title,
           int width, int height);
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_WINDOW_H
