#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T10:50:23
#   by: YU Yi skyvin.yu@gmail.com
#
#-------------------------------------------------

include(../defaults.pri)

#QT += gui
QT += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SunCloud
TEMPLATE = app
CONFIG += qt
#CONFIG += console

DESTDIR = ../bin/

INCLUDEPATH += "../_xlibs/include/boost/"
LIBS += "-L../_xlibs/lib/"
LIBS += "-L../lib -llibsuncloud"

SOURCES += \
    main.cc\
    mainwindow.cc \
    MainWindow.cc

HEADERS  += \
    mainwindow.h \
    MainWindow.h

FORMS    += \
    mainwindow.ui \
    MainWindow.ui



