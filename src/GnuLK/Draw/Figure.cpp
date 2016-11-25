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

#include <GnuLK/Draw/Figure_p.h>
#include <GnuLK/Draw/FigureScale.h>

GNULK_BEGIN_NAMESPACE

Figure::Figure(const String &name)
    : Figure(new FigurePrivate(this))
{
    GNULK_PUBLIC(Figure);
    m->name = name;
}


String Figure::name() const {
    GNULK_PUBLIC(const Figure);
    return m->name;
}


List<FigureScale*>& Figure::scale_list() {
    GNULK_PUBLIC(Figure);
    return m->scale_list;
}


const List<FigureScale*>& Figure::scale_list() const {
    GNULK_PUBLIC(const Figure);
    return m->scale_list;
}


FigureScale* Figure::scale(const String &name) {
    GNULK_PUBLIC(Figure);
    for (auto scale : m->scale_list) {
        if (scale->name() == name) {
            return scale;
        }
    }
    // not found
    return nullptr;
}


void Figure::add(FigureScale *scale) {
    GNULK_PUBLIC(Figure);
    m->scale_list.push_back(scale);
    scale->set_figure(this);
    m->update_layout();
}


void Figure::remove(FigureScale *scale) {
    GNULK_PUBLIC(Figure);
    m->scale_list.remove(scale);
    scale->set_figure(nullptr);
    m->update_layout();
}


void Figure::draw(const Rect &rect, Graphics &gc) {
    GNULK_PUBLIC(Figure);

    if (rect.is_empty()) {
        return;
    }

    m->on_error = false;
    gc.save();
    gc.set_font_size(m->font_size);
    gc.new_path();
    gc.rect(rect);
    gc.clip();

    /* if required fill the background with color */
    gc.draw_rect(rect, m->fill_color, m->stroke_color);

    /* draw all of the item's contents */
    double cell_width = rect.width() / m->layout_cols;
    double cell_height = rect.height() / m->layout_rows;

    for (auto scale : m->scale_list) {
        if (m->on_error == true) {
            break;
        }
        if (scale->visible()) {
            Rect scale_rect = scale->layout_rect();
            Rect position_rect(
                rect.x() + scale_rect.x() * cell_width,
                rect.y() + scale_rect.y() * cell_height,
                scale_rect.width() * cell_width,
                scale_rect.height() * cell_height
            );
            scale->draw(position_rect, gc);
        }
    }

    if (m->on_error == true) {
        gc.draw_rect(rect, m->fill_color, m->stroke_color);
        gc.set_color(m->error_message_color);
        gc.draw_text(40, 40, "Numeric error on item");
    }

    gc.restore();
}


void FigurePrivate::update_layout() {
    layout_rows = 0;
    layout_cols = 0;
    for (auto scale : scale_list) {
        Rect scale_rect = scale->layout_rect();
        if (scale_rect.right() > layout_cols) {
            layout_cols = scale_rect.right();
        }
        if (scale_rect.bottom() > layout_rows) {
            layout_rows = scale_rect.bottom();
        }
    }
}


void Figure::mouse_event(const MouseEvent &event) {
    GNULK_PUBLIC(Figure);
    for (auto scale : m->scale_list) {
        if (scale->visible() == true) {
            scale->mouse_event(event);
        }
    }
}


void Figure::inform_error() {
    GNULK_PUBLIC(Figure);
    m->on_error = true;
}

GNULK_END_NAMESPACE
