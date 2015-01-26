#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T10:50:23
#   by: YU Yi skyvin.yu@gmail.com
#
#-------------------------------------------------

include(../defaults.pri)

TARGET = libsuncloud
TEMPLATE = lib
CONFIG += staticlib
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../lib/

INCLUDEPATH += "../../_xlibs/include/boost/"
INCLUDEPATH += "../../ExternalLib/mdsplib/include"
INCLUDEPATH += "../../ExternalLib/mdsplib/src"
LIBS += "-L../../_xlibs/lib/"
LIBS += "-L../../ExternalLib/mdsplib/lib"
LIBS += "../../ExternalLib/mdsplib/lib/libmdsp.lib"

SOURCES += \
    MetarParser.cc \
    Metar.cc

HEADERS  += \
    MetarParser.h \
    Metar.h
