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

#ifndef GNULK_DRAW_CHART_H
#define GNULK_DRAW_CHART_H

#include <GnuLK/Draw/FigureView.h>

GNULK_BEGIN_NAMESPACE

class GNULK_EXPORT Chart
    : public FigureView
{
public:

    Chart(const String &title="GnuLK",
          int width=500, int height=400);


    virtual void plot(const Array1D &x,
                      const Array1D &y,
                      const char *style="bor",
                      const String &name="series");



protected:

    Chart(ObjectPrivate *priv,
          Figure *figure,
          const String &title,
          int width, int height)
        : FigureView(priv, figure, title, width, height)
    { }
};

GNULK_END_NAMESPACE

#endif // GNULK_DRAW_CHART_H
