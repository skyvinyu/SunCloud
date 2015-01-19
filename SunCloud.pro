#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T10:50:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SunCloud
TEMPLATE = app


SOURCES += main.cc\
        mainwindow.cc \
    src/MetarParser.cc

HEADERS  += mainwindow.h \
    include/MetarParser.h

FORMS    += mainwindow.ui

INCLUDEPATH += "../_xlibs/include/boost/"
INCLUDEPATH += "../ExternalLib/mdsplib/include"
INCLUDEPATH += "../ExternalLib/mdsplib/src"
LIBS += "-L../_xlibs/lib/"
LIBS += "-L../ExternalLib/mdsplib/lib"
