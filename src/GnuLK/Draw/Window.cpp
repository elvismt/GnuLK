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

#include <GnuLK/Draw/Window_p.h>
#include <GnuLK/Draw/Graphics_p.h>

GNULK_BEGIN_NAMESPACE

static bool _on_main = false;
static uint32_t _win_count = 0U;
static gboolean _on_close (GtkWidget *self, gpointer *data);
static gboolean _on_draw (GtkWidget *self, cairo_t *cr, gpointer *data);
static gboolean _on_mouse_press (GtkWidget *self, GdkEvent *event, gpointer *data);
static gboolean _on_mouse_move (GtkWidget *self, GdkEvent *event, gpointer *data);
static gboolean _on_mouse_release (GtkWidget *self, GdkEvent *event, gpointer *data);


Window::Window(ObjectPrivate *priv,
                const String &title,
                int width, int height)
    : Object(priv)
{
    GNULK_PUBLIC(Window);

    static bool once_called = false;
    if (!once_called) {
        static int argc = 1;
        static char argv[] = "GnuLK";
        char *argvp = &argv[0];
        char **argvpp = &argvp;
        gtk_init(&argc, &argvpp);
        once_called = true;
    }

    m->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    m->drawing_area = gtk_drawing_area_new();

    gtk_container_add(GTK_CONTAINER(m->window), m->drawing_area);
    gtk_window_set_title(GTK_WINDOW(m->window), title.c_str());
    gtk_window_set_default_size(GTK_WINDOW(m->window), width, height);
    gtk_widget_set_size_request(m->drawing_area, 250, 250);
    gtk_widget_add_events(m->drawing_area,
                   GDK_EXPOSURE_MASK
                   |GDK_BUTTON_PRESS_MASK
                   |GDK_BUTTON_RELEASE_MASK
                   |GDK_POINTER_MOTION_MASK);

    g_signal_connect(G_OBJECT(m->window), "destroy",
                     G_CALLBACK(_on_close), this);
    g_signal_connect(G_OBJECT(m->drawing_area), "draw",
                     G_CALLBACK(_on_draw), this);
    g_signal_connect(G_OBJECT(m->drawing_area), "button-press-event",
                     G_CALLBACK(_on_mouse_press), this);
    g_signal_connect(G_OBJECT(m->drawing_area), "motion-notify-event",
                     G_CALLBACK(_on_mouse_move), this);
    g_signal_connect(G_OBJECT(m->drawing_area), "button-release-event",
                     G_CALLBACK(_on_mouse_release), this);
}


Window::Window(const String &title, int width, int height)
    : Window(new WindowPrivate(this), title, width, height)
{ }


void Window::show() {
    GNULK_PUBLIC(Window);
    _win_count += 1U;
    gtk_widget_show_all(m->window);
}


void Window::hide() {
    GNULK_PUBLIC(Window);
    _win_count -= 1U;
    gtk_widget_hide(m->window);
    if (_on_main == true && _win_count == 0U) {
        gtk_main_quit();
        _on_main = false;
    }
}


void Window::run() {
    if (_on_main == false) {
        _on_main = true;
        gtk_main();
    }
}


void Window::draw(Graphics &gc) {
    GNULK_UNUSED(gc);
}


void Window::mouse_event(const MouseEvent &event) {
    GNULK_UNUSED(event);
}


Rect Window::rect() const {
    GNULK_PUBLIC(const Window);
    GtkAllocation alloc;
    gtk_widget_get_allocation(m->drawing_area, &alloc);
    return Rect(alloc.width, alloc.height);
}


void Window::redraw() {
    GNULK_PUBLIC(Window);
    gtk_widget_queue_draw(m->drawing_area);
}


static
gboolean _on_close (GtkWidget *self, gpointer *data) {
    Window *cppobj = (Window*) data;
    GNULK_UNUSED(self);
    cppobj->hide();
    return TRUE;
}


static
gboolean _on_draw (GtkWidget *self, cairo_t *cr, gpointer *data) {
    Window *cppobj = (Window*) data;
    GNULK_UNUSED(self);
    Graphics *gc = &(GNULK_GET_PRIVATE(Window,cppobj)->gc);

    GNULK_GET_PRIVATE(Graphics, gc)->cr = cr;

    cppobj->draw(*gc);

    return TRUE;
}


static
gboolean _on_mouse_press (GtkWidget *self, GdkEvent *event, gpointer *data) {
    Window *cppobj = (Window*) data;
    MouseEvent mouse_event;
    GNULK_UNUSED(self);

    mouse_event.action = MOUSE_PRESS;
    mouse_event.position = Point(event->button.x, event->button.y);

    if (event->button.button == 1) {
        mouse_event.button = MOUSE_LEFT_BUTTON;
        cppobj->mouse_event(mouse_event);
    } else if (event->button.button == 3) {
        mouse_event.button = MOUSE_RIGHT_BUTTON;
        cppobj->mouse_event(mouse_event);
    }

    return TRUE;
}


static
gboolean _on_mouse_move (GtkWidget *self, GdkEvent *event, gpointer *data) {
    Window *cppobj = (Window*) data;
    MouseEvent mouse_event;
    GNULK_UNUSED(self);

    mouse_event.action = MOUSE_MOVE;
    mouse_event.position = Point(event->button.x, event->button.y);
    mouse_event.button = MOUSE_NO_BUTTON;
    cppobj->mouse_event(mouse_event);

    return TRUE;
}


static
gboolean _on_mouse_release (GtkWidget *self, GdkEvent *event, gpointer *data) {
    Window *cppobj = (Window*) data;
    MouseEvent mouse_event;
    GNULK_UNUSED(self);

    mouse_event.action = MOUSE_RELEASE;
    mouse_event.position = Point(event->button.x, event->button.y);

    if (event->button.button == 1) {
        mouse_event.button = MOUSE_LEFT_BUTTON;
        cppobj->mouse_event(mouse_event);
    } else if (event->button.button == 3) {
        mouse_event.button = MOUSE_RIGHT_BUTTON;
        cppobj->mouse_event(mouse_event);
    }

    return TRUE;
}

GNULK_END_NAMESPACE
