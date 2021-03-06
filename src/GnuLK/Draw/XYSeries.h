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

#ifndef GNULK_XYSERIES_H
#define GNULK_XYSERIES_H

#include <GnuLK/Draw/FigureItem.h>
#include <GnuLK/Util/Array.h>

GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT XYSeries
   : public FigureItem
{
public:

    enum PointSymbol: uint32_t {
        LINE             = 0x00000001,
        CIRCLES          = 0x00000002
    };


    XYSeries(const Array1D &x,
             const Array1D &y,
             const char *style="bor",
             const String &name="series");

    virtual Rect figure_rect() const;
    virtual Rect data_rect() const;

    virtual void set_data(const Array1D &x,
                          const Array1D &y);

    virtual void set_style(const char *style);


protected:

   virtual void draw(Graphics &gc);

   XYSeries(ObjectPrivate *priv)
       : FigureItem(priv) {}
};

GNULK_END_NAMESPACE

#endif // GNULK_XYSERIES_H
