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

#include <GnuLK/Draw/FigureView_p.h>

GNULK_BEGIN_NAMESPACE

FigureView::FigureView(ObjectPrivate *priv,
                       Figure *figure,
                       const String &title,
                       int width, int height)
    : Window(priv, title, width, height)
{
    GNULK_PUBLIC(FigureView);

    if (figure != nullptr) {
        m->figure = figure;
        m->own_figure = false;
    } else {
        m->figure = new Figure();
        m->own_figure = true;
    }
}


FigureViewPrivate::~FigureViewPrivate() {
    if (own_figure == true) {
        delete figure;
    }
}


FigureView::FigureView(const String &title,
                       int width, int height)
    : FigureView(new FigureViewPrivate(this),
        nullptr, title, width, height)
{ }


Figure* FigureView::figure() const {
    GNULK_PUBLIC(const FigureView);
    return m->figure;
}


void FigureView::draw(Graphics &gc) {
    GNULK_PUBLIC(FigureView);

    m->figure->draw(rect(), gc);
}

GNULK_END_NAMESPACE
