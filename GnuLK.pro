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
    src/GnuLK/Draw/Color.h

SOURCES += \
    Test.cpp
