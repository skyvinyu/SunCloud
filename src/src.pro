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

#QMAKE_CXXFLAGS += -std=c++11

# Include and source path definition
INCLUDEPATH += "../../ExternalLib/_xlibs/include/"
INCLUDEPATH += "../../ExternalLib/mdsplib/include"
INCLUDEPATH += "../../ExternalLib/mdsplib/src"
INCLUDEPATH += "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include"
LIBS += "-L../../_xlibs/lib/"
LIBS += "-L../../ExternalLib/mdsplib/lib"
LIBS += "../../ExternalLib/mdsplib/lib/libmdsp.lib"

# Macro definition
DEFINES += DDEBUG
DEFINES += USE_BOOST_GEOMETRY

# Source code and header
SOURCES += \
    Metar.cc \
    QtLogger.cc \
    FlightRoute.cc \
    ApplicationException.cc \
    RestrictedArea.cc \
    MetarManager.cc \
    MetarKmlWriter.cc \
    FlightManager.cc \
    BarycentricInterpolation.cc \
    MetarWindFilter.cc \
    MultiMetarFilter.cc \
    MetarSkyCoverFilter.cc \
    IndexedMetar.cc \
    MetarHandler.cc \
    TimePointToAndFromString.cc \
    MetarFileReader.cc
#    FlightRouteScilabWriter.cc

HEADERS  += \
    Metar.h \
    LogService.h \
    QtLogger.h \
    Geometry.h \
    FlightRoute.h \
    Contract.h \
    ApplicationException.h \
    RestrictedArea.h \
    MetarManager.h \
    IMetarWriter.h \
    MetarKmlWriter.h \
    FlightManager.h \
    CustomGeometry.h \
    IInterpolation.h \
    BarycentricInterpolation.h \
    IMetarFilter.h \
    MetarWindFilter.h \
    Constant.h \
    MultiMetarFilter.h \
    MetarSkyCoverFilter.h \
    CustomGeometryIndexer.h \
    IndexedMetar.h \
    MetarHandler.h \
    TimePointToAndFromString.h \
    IMetarReader.h \
    MetarFileReader.h
#    IFlightRouteWriter.h \
#    FlightRouteScilabWriter.h
