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

#include <GnuLK/Draw/XYScale_p.h>
#include <GnuLK/Draw/FigureItem.h>
#include <GnuLK/Draw/XYSeries.h>
#include <cmath>

GNULK_BEGIN_NAMESPACE

XYScale::XYScale(const String &name)
    : XYScale(new XYScalePrivate(this))
{
    GNULK_PUBLIC(XYScale);
    m->name = name;

    m->axis[AXIS_BOTTOM] = new PlotAxis(
        "BottomAxis",
        PlotAxis::HORIZONTAL,
        PlotAxis::EVERITHING
    );

    m->axis[AXIS_LEFT] = new PlotAxis(
        "LeftAxis",
        PlotAxis::VERTICAL,
        PlotAxis::EVERITHING
    );

    m->axis[AXIS_TOP] = new PlotAxis(
        "TopAxis",
        PlotAxis::HORIZONTAL,
        PlotAxis::EVERITHING
    );

    m->axis[AXIS_RIGHT] = new PlotAxis(
        "RightAxis",
        PlotAxis::VERTICAL,
        PlotAxis::EVERITHING
    );

    for (auto axis : m->axis) {
        axis->set_scale(this);
    }
    rescale();
}


Rect XYScale::figure_rect() const {
    GNULK_PUBLIC(const XYScale);
    return Rect(m->fig_x_min, m->fig_y_min,
                m->fig_width, m->fig_height);
}


Rect XYScale::data_rect() const {
    GNULK_PUBLIC(const XYScale);
    return Rect(m->dat_x_min, m->dat_y_min,
                m->dat_width, m->dat_height);
}


Point XYScale::map(const Point &p) const {
    GNULK_PUBLIC(const XYScale);
    Point ret;
    double tmp;

    tmp = (p.x() - m->dat_x_min) / m->dat_width;
    ret.set_x(m->fig_x_min + tmp*m->fig_width);

    tmp = (p.y() - m->dat_y_min) / m->dat_height;
    ret.set_y(m->fig_y_max - tmp*m->fig_height);

    return ret;
}


Point XYScale::unmap(const Point &p) const {
    GNULK_PUBLIC(const XYScale);
    Point ret;
    double tmp;

    tmp = (p.x() - m->fig_x_min) / m->fig_width;
    ret.set_x(m->dat_x_min + tmp*m->dat_width);

    tmp = (m->fig_y_max - p.y()) / m->fig_height;
    ret.set_y(m->dat_y_min + tmp*m->dat_height);

    return ret;
}


void XYScale::rescale() {
    GNULK_PUBLIC(XYScale);

    m->on_error = false;
    if (m->item_list.size() == 0) {
        set_x_range(0.0, 1.0);
        set_y_range(0.0, 1.0);
        return;
    }

    auto iter = m->item_list.begin();
    auto end = m->item_list.end();
    FigureItem *item = *iter;
    Rect item_rect = item->data_rect();

    bool some_rescales = false;
    while (iter != end) {
        if (item->rescalable() == true) {
            some_rescales = true;
            break;
        } else {
            item = *iter++;
        }
    }
    if (some_rescales == false) {
        set_x_range(0.0, 1.0);
        set_y_range(0.0, 1.0);
        return;
    }

    m->dat_x_min = item_rect.left();
    m->dat_x_max = item_rect.right();
    m->dat_y_min = item_rect.top();
    m->dat_y_max = item_rect.bottom();

    while (iter != end) {
        item = *iter++;
        if (item->rescalable() == true) {
            item_rect = item->data_rect();

            if (item_rect.left() < m->dat_x_min) {
                m->dat_x_min = item_rect.left();
            }
            if (item_rect.right() > m->dat_x_max) {
                m->dat_x_max = item_rect.right();
            }
            if (item_rect.top() < m->dat_y_min) {
                m->dat_y_min = item_rect.top();
            }
            if (item_rect.bottom() > m->dat_y_max) {
                m->dat_y_max = item_rect.bottom();
            }
        }
    }

    if (!std::isfinite(m->dat_x_min) ||
        !std::isfinite(m->dat_x_max) ||
        !std::isfinite(m->dat_y_min) ||
        !std::isfinite(m->dat_y_max) )
    {
        m->on_error = true;
    }

    m->apply_padding();
}


void XYScalePrivate::apply_padding() {
    dat_width = dat_x_max - dat_x_min;
    double padding = dat_width * x_padding;
    if (dat_width == 0.0) {
        padding = 0.1 * std::fabs(dat_x_max);
        if (padding == 0) {
            padding = 0.1;
        }
    }
    dat_x_min -= padding;
    dat_x_max += padding;
    dat_width += 2.0*padding;

    dat_height = dat_y_max - dat_y_min;
    padding = dat_height * y_padding;
    if (dat_height == 0.0) {
        padding = 0.1 * std::fabs(dat_y_max);
        if (padding == 0) {
            padding = 0.1;
        }
    }
    dat_y_min -= padding;
    dat_y_max += padding;
    dat_height += 2.0*padding;
}


void XYScale::draw(const Rect &rect, Graphics &gc) {
    GNULK_PUBLIC(XYScale);

    if (m->on_error == true) {
        m->inform_figure_error();
        return;
    }

    /* restrict drawing to within the horizontal margin */
    m->fig_x_min = rect.left() + m->left_margin;
    m->fig_x_max = rect.right() - m->right_margin;
    m->fig_width = m->fig_x_max - m->fig_x_min;

    /* restrict drawing to within the vertical margin */
    m->fig_y_min = rect.top() + m->top_margin;
    m->fig_y_max = rect.bottom() - m->bottom_margin;
    m->fig_height = m->fig_y_max - m->fig_y_min;

    /* clip to the area defined by the margin */
    gc.save();
    gc.new_path();
    gc.rect(this->figure_rect());
    gc.clip();

    /* let the parent classe's method draw the
     * background and all of the items. If in the
     * process of zooming draw a rectangle */
    FigureScale::draw(rect, gc);
    if (m->mouse_moving == true && m->mouse_mode == MOUSE_ZOOMS) {
        m->draw_zoom_rect(gc);
    }

    /* return gc in the same state it has entered
     * this method */
    gc.restore();

    m->position_axis();
    for (auto axis : m->axis) {
        if (axis->visible()) {
            axis->draw(gc);
        }
    }
}


void XYScalePrivate::position_axis() {
    axis[XYScale::AXIS_BOTTOM]->set_range(dat_x_min, dat_x_max);
    axis[XYScale::AXIS_BOTTOM]->set_anchor(dat_y_min);

    axis[XYScale::AXIS_LEFT]->set_range(dat_y_min, dat_y_max);
    axis[XYScale::AXIS_LEFT]->set_anchor(dat_x_min);

    axis[XYScale::AXIS_TOP]->set_range(dat_x_min, dat_x_max);
    axis[XYScale::AXIS_TOP]->set_anchor(dat_y_max);

    axis[XYScale::AXIS_RIGHT]->set_range(dat_y_min, dat_y_max);
    axis[XYScale::AXIS_RIGHT]->set_anchor(dat_x_max);
}


void XYScalePrivate::draw_zoom_rect(Graphics &gc) {
    static double dashes[] = {3.0, 3.0};
    gc.save();
    gc.set_width(1.0);
    gc.set_antialias(false);
    gc.set_dashed_line(dashes, 2);
    gc.new_path();
    gc.set_color(zoom_rect_color);
    gc.rect(Rect(zoom_p1, zoom_p2));
    gc.stroke();
    gc.restore();
}


void XYScale::mouse_event(const MouseEvent &event) {
    GNULK_PUBLIC(XYScale);
    if (figure_rect().contains(event.position) == false) {
        if (m->mouse_moving == true) {
            m->mouse_moving = false;
            m->inform_figure_change();
        }
        return;
    }

    if (m->mouse_mode == MOUSE_ZOOMS) {
        m->zoom_mouse_event(event);
    } else {
        m->translate_mouse_event(event);
    }
}


void XYScalePrivate::zoom_mouse_event(const MouseEvent &event) {
    GNULK_PRIVATE(XYScale);
    if (event.action == MOUSE_PRESS) {
        if (event.button == MOUSE_LEFT_BUTTON) {
            mouse_moving = true;
            zoom_p1 = event.position;
            zoom_p2 = event.position;
        }
        else if (event.button == MOUSE_RIGHT_BUTTON) {
            mouse_moving = false;
            m->rescale();
            inform_figure_change();
        }
    }

    else if (event.action == MOUSE_MOVE) {
        if (mouse_moving == true) {
            zoom_p2 = event.position;
            inform_figure_change();
        }
    }

    else if (event.action == MOUSE_RELEASE) {
        if (mouse_moving == true) {
            mouse_moving = false;
            if (zoom_p1.dist_sqr(zoom_p2) > 16.0)
                m->track_figure_rect(Rect(zoom_p1, zoom_p2));
            inform_figure_change();
        }
    }
}


void XYScalePrivate::translate_mouse_event(const MouseEvent &event) {
    GNULK_PRIVATE(XYScale);
    if (event.action == MOUSE_PRESS) {
        if (event.button == MOUSE_LEFT_BUTTON) {
            mouse_moving = true;
            zoom_p1 = event.position;
            zoom_p2 = event.position;
        }
        else if (event.button == MOUSE_RIGHT_BUTTON) {
            mouse_moving = false;
            m->rescale();
            inform_figure_change();
        }
    }

    else if (event.action == MOUSE_MOVE) {
        if (mouse_moving == true) {
            zoom_p2 = event.position;
            Rect figure_rect = m->figure_rect();
            figure_rect.translate(zoom_p1 - zoom_p2);
            m->track_figure_rect(figure_rect);
            zoom_p1 = zoom_p2;
            inform_figure_change();
        }
    }

    else if (event.action == MOUSE_RELEASE) {
        mouse_moving = false;
    }
}


XYScale::MouseMode XYScale::mouse_mode() const {
    GNULK_PUBLIC(XYScale);
    return m->mouse_mode;
}


void XYScale::set_mouse_mode(MouseMode mode) {
    GNULK_PUBLIC(XYScale);
    m->mouse_mode = mode;
}


void XYScale::track_data_rect(const Rect &rect) {
    set_x_range(rect.left(), rect.right());
    set_y_range(rect.top(), rect.bottom());
}


void XYScale::track_figure_rect(const Rect &rect) {
    Point p1 = unmap(rect.top_left());
    Point p2 = unmap(rect.bottom_right());
    track_data_rect(Rect(p1,p2));
}


void XYScale::set_x_range(double min, double max) {
    GNULK_PUBLIC(XYScale);
    m->dat_x_min = min;
    m->dat_x_max = max;
    m->dat_width = max - min;
}


void XYScale::set_y_range(double min, double max) {
    GNULK_PUBLIC(XYScale);
    m->dat_y_min = min;
    m->dat_y_max = max;
    m->dat_height = max - min;
}


XYSeries* XYScale::plot(const Array1D &x,
                        const Array1D &y,
                        const char *style,
                        const String &name)
{
    XYSeries *series = new XYSeries(x, y, style, name);
    add(series);
    return series;
}

GNULK_END_NAMESPACE
