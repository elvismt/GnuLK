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

#ifndef GNULK_XYSCALE_H
#define GNULK_XYSCALE_H

#include <GnuLK/Draw/FigureScale.h>

GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT XYScale
   : public FigureScale
{
public:

    XYScale(const String &name="scale");

   virtual Rect figure_rect() const;
   virtual Rect data_rect() const;

   virtual Point map(const Point &p) const;
   virtual Point unmap(const Point &p) const;

   virtual void rescale();

    void set_x_range(double min, double max);
    void set_y_range(double min, double max);

    virtual void track_data_rect(const Rect &rect);
    virtual void track_figure_rect(const Rect &rect);


protected:

   virtual void draw(const Rect &rect, Graphics &gc);

    virtual void mouse_event(const MouseEvent &event);

   XYScale(ObjectPrivate *priv)
       : FigureScale(priv) {}
};

GNULK_END_NAMESPACE

#endif // GNULK_XYSCALE_H
