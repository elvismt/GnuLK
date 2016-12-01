TEMPLATE = app
TARGET = GnuLK
CONFIG -= qt
CONFIG += c++11
CONFIG += link_pkgconfig
PKGCONFIG = gtk+-3.0
DEFINES += GNULK_BUILD_DEBUG
INCLUDEPATH += src

HEADERS += \
    src/GnuLK/Util/Global.h \
    src/GnuLK/Draw/Point.h \
    src/GnuLK/Draw/Rect.h \
    src/GnuLK/Draw/Color.h \
    src/GnuLK/Util/Object_p.h \
    src/GnuLK/Util/Object.h \
    src/GnuLK/Draw/Canvas.h \
    src/GnuLK/Draw/Canvas_p.h \
    src/GnuLK/Draw/Window.h \
    src/GnuLK/Draw/Window_p.h \
    src/GnuLK/Draw/Graphics.h \
    src/GnuLK/Draw/Graphics_p.h \
    src/GnuLK/Draw/Figure.h \
    src/GnuLK/Draw/Figure_p.h \
    src/GnuLK/Draw/FigureView.h \
    src/GnuLK/Draw/FigureView_p.h \
    src/GnuLK/Util/Math.h \
    src/GnuLK/Util/Array_p.h \
    src/GnuLK/Draw/FigureScale.h \
    src/GnuLK/Draw/FigureScale_p.h \
    src/GnuLK/Draw/FigureItem.h \
    src/GnuLK/Draw/FigureItem_p.h \
    src/GnuLK/Draw/XYScale.h \
    src/GnuLK/Draw/XYScale_p.h \
    src/GnuLK/Draw/XYSeries.h \
    src/GnuLK/Draw/XYSeries_p.h \
    src/GnuLK/Draw/MouseEvent.h \
    src/GnuLK/Util/Array1.h \
    src/GnuLK/Util/Array.h \
    src/GnuLK/Util/ArrayData.h \
    src/GnuLK/Draw/Chart.h \
    src/GnuLK/Draw/Chart_p.h \
    src/GnuLK/Draw/PlotAxis.h \
    src/GnuLK/Draw/PlotAxis_p.h

SOURCES += \
    Test.cpp \
    src/GnuLK/Draw/Window.cpp \
    src/GnuLK/Draw/Graphics.cpp \
    src/GnuLK/Draw/Figure.cpp \
    src/GnuLK/Draw/FigureView.cpp \
    src/GnuLK/Draw/FigureScale.cpp \
    src/GnuLK/Draw/FigureItem.cpp \
    src/GnuLK/Draw/XYScale.cpp \
    src/GnuLK/Draw/XYSeries.cpp \
    src/GnuLK/Draw/Chart.cpp \
    src/GnuLK/Draw/PlotAxis.cpp
