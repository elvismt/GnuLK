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

#include <GnuLK/Draw/Graphics.h>
#include <GnuLK/Draw/MouseEvent.h>

GNULK_BEGIN_NAMESPACE
class FigureItem;
class FigureScale;
class FigureView;
GNULK_END_NAMESPACE


GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT Figure
    : public Object
{
public:

    Figure(const String &name="GnuLK");

    FigureView* view() const;

    String name() const;
    void set_name(const String &name);

    List<FigureScale*>& scale_list();
    const List<FigureScale*>& scale_list() const;
    FigureScale* scale(const String &name);

    virtual void add(FigureScale *item);
    inline void add(FigureScale &scale) { add(&scale); }

    virtual void remove(FigureScale *scale);
    inline void remove(FigureScale &scale) { remove(&scale); }
    inline void remove(const String &title) { remove(scale(title)); }

    virtual void draw(const Rect &rect, Graphics &gc);

    void save_png(const String &filename,
                  const Rect &size=Rect(600,500));

    virtual void inform_error();

    virtual void inform_look_change(FigureItem *item);

    virtual void inform_data_change(FigureItem *item);


protected:

    friend class FigureView;

    virtual void mouse_event(const MouseEvent &event);

    virtual void set_view(FigureView *view);

    Figure(ObjectPrivate *priv)
        : Object(priv)
    { }
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_FIGURE_H
