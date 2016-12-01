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

    auto x = arange(0.0, 2.0*M_PI, 0.2);

    chart.subplots(2, 1);
    chart(0,0)->plot(x, sin(x), "kor");
    chart(1,0)->plot(x, cos(x), "kob");
    chart.show();

    Window::run();
    return 0;
}
