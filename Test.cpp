/*
 * This file is part of GnuLK.
 *
 * Copyright (c) 2016  Elvis M. Teixeira
 *
 * GnuLK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GnuLK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GnuLK.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <GnuLK/Draw/Rect.h>
using namespace GnuLK;

#include <iostream>
using namespace std;


int main()
{
    Point p1(3,4), p2(5,6);

    cout << "p1: " << p1 << endl;
    cout << "p1 + p2: " << p1+p2 << endl;

    return 0;
}
