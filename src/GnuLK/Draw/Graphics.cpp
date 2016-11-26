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

#include <GnuLK/Draw/Graphics_p.h>
#include <GnuLK/Draw/Canvas_p.h>

GNULK_BEGIN_NAMESPACE

Graphics::Graphics(Canvas *canvas)
    : Object(new GraphicsPrivate(this))
{
    auto gp = GNULK_GET_PRIVATE(Graphics, this);
    gp->own_cr = false;

    if (canvas != nullptr) {
        auto cp = GNULK_GET_PRIVATE(Canvas,canvas);

        if (cp->cr != nullptr) {
            gp->cr = cp->cr;
        }
        else if (cp->surf != nullptr) {
            gp->cr = cairo_create(cp->surf);
            gp->own_cr = true;
        }
    }
    else {
        gp->cr = nullptr;
    }
}


GraphicsPrivate::~GraphicsPrivate() {
    if (own_cr == true) {
        cairo_destroy(cr);
    }
}


void Graphics::new_path() {
    GNULK_PUBLIC(Graphics);
    cairo_new_path(m->cr);
}


void Graphics::stroke() {
    GNULK_PUBLIC(Graphics);
    cairo_stroke(m->cr);
}


void Graphics::stroke_preserve() {
    GNULK_PUBLIC(Graphics);
    cairo_stroke_preserve(m->cr);
}


void Graphics::fill() {
    GNULK_PUBLIC(Graphics);
    cairo_fill(m->cr);
}


void Graphics::fill_preserve() {
    GNULK_PUBLIC(Graphics);
    cairo_fill_preserve(m->cr);
}


void Graphics::clip() {
    GNULK_PUBLIC(Graphics);
    cairo_clip(m->cr);
}


void Graphics::clip_preserve() {
    GNULK_PUBLIC(Graphics);
    cairo_clip_preserve(m->cr);
}


void Graphics::set_color(const Color &c) {
    GNULK_PUBLIC(Graphics);
    cairo_set_source_rgba(m->cr,
        c.red_f(), c.green_f(), c.blue_f(), c.alpha_f());
}


void Graphics::set_width(double w) {
    GNULK_PUBLIC(Graphics);
    cairo_set_line_width(m->cr, w);
}


void Graphics::save() {
    GNULK_PUBLIC(Graphics);
    cairo_save(m->cr);
}


void Graphics::restore() {
    GNULK_PUBLIC(Graphics);
    cairo_restore(m->cr);
}


void Graphics::translate(double dx, double dy) {
    GNULK_PUBLIC(Graphics);
    cairo_translate(m->cr, dx, dy);
}


void Graphics::set_antialias(bool antialias) {
    GNULK_PUBLIC(Graphics);
    cairo_set_antialias(m->cr,
    antialias ? CAIRO_ANTIALIAS_SUBPIXEL
              : CAIRO_ANTIALIAS_NONE);
}


void Graphics::set_dashed_line(const double *dashes, int num_dashes) {
    GNULK_PUBLIC(Graphics);
    cairo_set_dash(m->cr, dashes, num_dashes, 0.0);
}


void Graphics::rotate(double a) {
    GNULK_PUBLIC(Graphics);
    cairo_rotate(m->cr, a);
}


void Graphics::move_to(double x, double y) {
    GNULK_PUBLIC(Graphics);
    cairo_move_to(m->cr, x, y);
}


void Graphics::line_to(double x, double y) {
    GNULK_PUBLIC(Graphics);
    cairo_line_to(m->cr, x, y);
}


void Graphics::rect(double x, double y, double w, double h) {
    GNULK_PUBLIC(Graphics);
    cairo_rectangle(m->cr, x, y, w, h);
}


void Graphics::arc(double x, double y, double r, double a1, double a2) {
    GNULK_PUBLIC(Graphics);
    cairo_arc(m->cr, x, y, r, a1, a2);
}


void Graphics::circle(double x, double y, double r) {
    GNULK_PUBLIC(Graphics);
    cairo_move_to(m->cr, x+r, y);
    cairo_arc(m->cr, x, y, r, 0.0, 6.28318530718);
}


static inline
void try_fill_stroke (cairo_t *cr, const Color &fill,
                             const Color &stroke)
{
    if (!fill.is_null() && !stroke.is_null())
    {
        /* in case both colors are active fill background and
         * then stroke the border */
        cairo_set_source_rgba(cr, fill.red_f(),
            fill.green_f(), fill.blue_f(), fill.alpha_f());
        cairo_fill_preserve(cr);
        cairo_set_source_rgba(cr, stroke.red_f(),
            stroke.green_f(), stroke.blue_f(), stroke.alpha_f());
        cairo_stroke(cr);
    }
    else if (!fill.is_null())
    {
        /* in case only the fill color is active, only fill */
        cairo_set_source_rgba(cr, fill.red_f(),
            fill.green_f(), fill.blue_f(), fill.alpha_f());
        cairo_fill(cr);
    }
    else
    {
        /* in case only the stroke color is active, only stroke */
        cairo_set_source_rgba(cr, stroke.red_f(),
            stroke.green_f(), stroke.blue_f(), stroke.alpha_f());
        cairo_stroke(cr);
    }
}


void Graphics::draw_line(double x1, double y1, double x2, double y2,
               const Color &color)
{
    GNULK_PUBLIC(Graphics);
    if (!color.is_null()) {
        cairo_move_to(m->cr, x1, y1);
        cairo_line_to(m->cr, x2, y2);
        cairo_set_source_rgba(m->cr, color.red_f(),
            color.green_f(), color.blue_f(), color.alpha_f());
        cairo_stroke(m->cr);
    }
}


void Graphics::draw_circle(double x, double y, double r,
                           const Color &fill, const Color &stroke)
{
    GNULK_PUBLIC(Graphics);
    if (!fill.is_null() || !stroke.is_null()) {
        cairo_new_path(m->cr);
        cairo_move_to(m->cr, x+r, y);
        cairo_arc(m->cr, x, y, r, 0.0, 6.28318530718);
        try_fill_stroke(m->cr, fill, stroke);
    }
}


void Graphics::draw_rect(const Rect &rect, const Color &fill,
                         const Color &stroke)
{
    GNULK_PUBLIC(Graphics);
    if (!fill.is_null() || !stroke.is_null()) {
        cairo_new_path(m->cr);
        cairo_rectangle(m->cr, rect.x(), rect.y(),
            rect.width(), rect.height());
        try_fill_stroke(m->cr, fill, stroke);
    }
}


void Graphics::draw_text(double x, double y, const char *txt) {
    GNULK_PUBLIC(Graphics);
    cairo_move_to(m->cr, x, y);
    cairo_show_text(m->cr, txt);
}


void Graphics::set_font_size(double font_size) {
    GNULK_PUBLIC(Graphics);
    cairo_set_font_size(m->cr, font_size);
}

GNULK_END_NAMESPACE
