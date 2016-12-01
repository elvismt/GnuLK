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

#ifndef GNULK_DRAW_CHART_P_H
#define GNULK_DRAW_CHART_P_H

#include <GnuLK/Draw/Chart.h>
#include <GnuLK/Draw/FigureView_p.h>

GNULK_BEGIN_NAMESPACE

class ChartPrivate
    : public FigureViewPrivate
{
public:

    ChartPrivate(Chart *publ)
        : FigureViewPrivate(publ)
    { }

    FigureScale* create_default_scale();


    Vector<Vector<FigureScale*> > scales;
    List<FigureItem*> item_list;
    List<FigureScale*> scale_list;
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_CHART_P_H
