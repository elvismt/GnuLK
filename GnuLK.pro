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
    src/GnuLK/Util/Vec2D.h


