#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T10:50:23
#   by: YU Yi skyvin.yu@gmail.com
#
#-------------------------------------------------

# General configuration definition
include(../defaults.pri)

TARGET = libsuncloud
TEMPLATE = lib
CONFIG += staticlib
CONFIG -= app_bundle
#CONFIG -= qt

DESTDIR = ../lib/

# Include and source path definition
INCLUDEPATH += "../../ExternalLib/_xlibs/include/"
INCLUDEPATH += "../../ExternalLib/mdsplib/include"
INCLUDEPATH += "../../ExternalLib/mdsplib/src"
LIBS += "-L../../_xlibs/lib/"
LIBS += "-L../../ExternalLib/mdsplib/lib"
LIBS += "../../ExternalLib/mdsplib/lib/libmdsp.lib"

# Macro definition
DEFINES += DDEBUG
DEFINES += USE_BOOST_GEOMETRY

# Source code and header
SOURCES += \
    MetarParser.cc \
    Metar.cc \
    QtLogger.cc \
    FlightRoute.cc \
    ApplicationException.cc \
    RestrictedArea.cc


HEADERS  += \
    MetarParser.h \
    Metar.h \
    LogService.h \
    QtLogger.h \
    Geometry.h \
    FlightRoute.h \
    Contract.h \
    ApplicationException.h \
    RestrictedArea.h
