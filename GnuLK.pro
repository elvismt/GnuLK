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
    src/GnuLK/Draw/FigureBaseItem.h \
    src/GnuLK/Draw/FigureBaseItem_p.h \
    src/GnuLK/Draw/FigureScale.h \
    src/GnuLK/Draw/FigureScale_p.h

SOURCES += \
    Test.cpp \
    src/GnuLK/Draw/Window.cpp \
    src/GnuLK/Draw/Graphics.cpp \
    src/GnuLK/Draw/Figure.cpp \
    src/GnuLK/Draw/FigureView.cpp \
    src/GnuLK/Draw/FigureBaseItem.cpp \
    src/GnuLK/Draw/FigureScale.cpp
