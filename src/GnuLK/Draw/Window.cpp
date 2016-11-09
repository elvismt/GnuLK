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


Window::Window(ObjectPrivate *priv)
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

    g_signal_connect(G_OBJECT(m->window), "destroy",
                     G_CALLBACK(_on_close), this);
    g_signal_connect(G_OBJECT(m->drawing_area), "draw",
                     G_CALLBACK(_on_draw), this);
}


Window::Window(const String &title, int width, int height)
    : Window(new WindowPrivate(this))
{
    GNULK_PUBLIC(Window);

    gtk_window_set_title(GTK_WINDOW(m->window), title.c_str());
    gtk_window_set_default_size(GTK_WINDOW(m->window), width, height);
}


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


Rect Window::rect() const {
    GNULK_PUBLIC(const Window);
    GtkAllocation alloc;
    gtk_widget_get_allocation(m->drawing_area, &alloc);
    return Rect(alloc.width, alloc.height);
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
    Graphics *gc = &GNULK_GET_PRIVATE(Window,cppobj)->gc;

    GNULK_GET_PRIVATE(Graphics, gc)->cr = cr;

    cppobj->draw(*gc);

    return TRUE;
}

GNULK_END_NAMESPACE
