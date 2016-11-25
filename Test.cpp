/*
 * This file is part of GnuLK.
 *
 * Copyright (c) 2016  Elvis M. Teixeira
 *
 * GnuLK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * GnuLK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with GnuLK.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <GnuLK/Draw/FigureView.h>
using namespace GnuLK;

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    FigureView view;
    XYScale scale;

    const int n_pts = 60;
    Array1D x(n_pts), y(n_pts);
    const double step = 2 * M_PI / n_pts;
    for (int k=0; k<n_pts; ++k) {
        x[k] = k * step;
        y[k] = sin(4*x[k]) + 0.2*x[k]*x[k];
    }

    XYSeries sine_series(x, y, "bog");
    scale.add(sine_series);

    view.figure()->add(scale);
    view.show();

    Window::run();
    return 0;
}
