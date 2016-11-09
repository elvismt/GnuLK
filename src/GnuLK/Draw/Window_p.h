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

#ifndef GNULK_UTIL_WINDOW_P_H
#define GNULK_UTIL_WINDOW_P_H

#include <GnuLK/Draw/Window.h>
#include <gtk/gtk.h>

GNULK_BEGIN_NAMESPACE

class WindowPrivate
    : public ObjectPrivate
{
public:

    WindowPrivate(Window *publ)
        : ObjectPrivate(publ)
    { }


    GtkWidget *window;
    GtkWidget *drawing_area;

    Graphics gc;
};

GNULK_END_NAMESPACE

#endif // GNULK_UTIL_WINDOW_P_H
