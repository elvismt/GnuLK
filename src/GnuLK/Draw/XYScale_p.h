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

#ifndef GNULK_XYSCALE_P_H
#define GNULK_XYSCALE_P_H

#include <GnuLK/Draw/XYScale.h>
#include <GnuLK/Draw/FigureScale_p.h>

GNULK_BEGIN_NAMESPACE

class XYScalePrivate
   : public FigureScalePrivate
{
public:

    XYScalePrivate(XYScale *publ)
       : FigureScalePrivate(publ)
       , left_margin(20), right_margin(20)
       , top_margin(20), bottom_margin(20)
       , x_padding(0), y_padding(0)
    { }

    double left_margin, right_margin;
    double top_margin, bottom_margin;
    double x_padding, y_padding;

    double fig_x_min, fig_x_max;
    double fig_y_min, fig_y_max;
    double fig_width, fig_height;

    double dat_x_min, dat_x_max;
    double dat_y_min, dat_y_max;
    double dat_width, dat_height;
};

GNULK_END_NAMESPACE

#endif // GNULK_XYSCALE_P_H
