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

#include <GnuLK/Draw/Window.h>
using namespace GnuLK;

#include <iostream>
using namespace std;


class Circle: public Window {
    void draw(Graphics &gc)
    {
        Rect rec = rect();
        gc.set_color(Color::WHITE);
        gc.rect(rec);
        gc.fill();

        gc.set_width(3.0);
        gc.circle(rec.center(), 100.0);

        gc.set_color(Color::GREEN);
        gc.fill_preserve();
        gc.set_color(Color::BLUE);
        gc.stroke();
    }
};


int main()
{
    Circle win;

    win.show();

    Window::run();
    return 0;
}
