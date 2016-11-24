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
#include <GnuLK/Util/Array_p.h>
using namespace GnuLK;

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    FigureView view;
    XYScale scale;

    Vector<double> x, ys, yc;
    const uint32_t npts = 60;
    const double step = 2.0*M_PI/npts;
    for (uint32_t k=0; k<npts; ++k) {
        double t = k * step;
        x.push_back(t);
        ys.push_back(4*sin(4*t) + t*t);
        yc.push_back(4*cos(4*t) + 0.4*t*t);
    }

    XYSeries sine_series(x, ys);
    scale.add(sine_series);

    XYSeries cossine_series(x, yc);
    scale.add(cossine_series);

    view.figure()->add(scale);
    view.show();

    Window::run();
    return 0;
}
