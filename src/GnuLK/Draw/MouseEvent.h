/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 LSBD Adaptive Databases Group
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef GNULK_MOUSEEVENT_H
#define GNULK_MOUSEEVENT_H

#include <GnuLK/Draw/Point.h>

GNULK_BEGIN_NAMESPACE

enum MouseButton: uint32_t {
    MOUSE_LEFT_BUTTON,
    MOUSE_RIGHT_BUTTON,
    MOUSE_NO_BUTTON
};


enum MouseAction: uint32_t {
    MOUSE_PRESS,
    MOUSE_MOVE,
    MOUSE_RELEASE
};


struct MouseEvent {
    MouseButton button;
    MouseAction action;
    Point position;
};

GNULK_END_NAMESPACE

#endif // GNULK_MOUSEEVENT_H
