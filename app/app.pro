#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T10:50:23
#   by: YU Yi skyvin.yu@gmail.com
#
#-------------------------------------------------

include(../defaults.pri)


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SunCloud
TEMPLATE = app
CONFIG += console

DESTDIR = ../bin/

INCLUDEPATH += "../_xlibs/include/boost/"
LIBS += "-L../_xlibs/lib/"
LIBS += "-L../lib -llibsuncloud"

SOURCES += \
    main.cc\
    mainwindow.cc

HEADERS  += \
    mainwindow.h \
    ui_mainwindow.h

FORMS    += \
    mainwindow.ui



