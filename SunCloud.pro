#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T10:50:23
#   by: YU Yi skyvin.yu@gmail.com
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SunCloud
TEMPLATE = app


SOURCES += \
    src/main.cc\
    src/mainwindow.cc \
    src/MetarParser.cc \
    src/Metar.cc

HEADERS  += \
    include/mainwindow.h \
    include/MetarParser.h \
    include/Metar.h \
    include/ui_mainwindow.h

FORMS    += \
    ui/mainwindow.ui

INCLUDEPATH += "../_xlibs/include/boost/"
INCLUDEPATH += "../ExternalLib/mdsplib/include"
INCLUDEPATH += "../ExternalLib/mdsplib/src"
LIBS += "-L../_xlibs/lib/"
LIBS += "-L../ExternalLib/mdsplib/lib"
LIBS += "../ExternalLib/mdsplib/lib/libmdsp.lib"
