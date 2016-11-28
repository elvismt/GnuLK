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

#include <GnuLK/Draw/Chart.h>
using namespace GnuLK;

int main()
{
    Chart chart;

    auto x = arange(0.0, 2.0*M_PI, 0.1);
    chart.plot(x, array(x.size(), [&](uint32_t k, double &x) {
        x = sin(0.8*k) + 0.004*k*k;
    }), "kor");

    chart.plot(x, array(x.size(), [&](uint32_t k, double &x) {
        x = cos(0.4*k) + 0.002*k*k;
    }), "kog");

    chart.show();
    Window::run();
    return 0;
}
