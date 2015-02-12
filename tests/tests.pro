include(../defaults.pri)

QT      += testlib
QT      -= gui
TARGET   = Test
CONFIG  += console
CONFIG  -= app_bundle
TEMPLATE = app
SOURCES += tests_runner.cc \
           MetarTest.cc
HEADERS += AutoTest.h \
           MetarTest.h

#INCLUDEPATH += C:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/unittest-cpp_1_4/src
#INCLUDEPATH += $$TOP_OUT_PWD/ExternalLib/unittest-cpp_1_4/src
#INCLUDEPATH += ../ExternalLib/unittest-cpp_1_4/src
INCLUDEPATH += "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include"

#LIBS += -LC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/unittest-cpp_1_4/x64/Debug -lUnitTest++.vsnet2005.debug

LIBS += -L$$TOP_PWD/lib -llibsuncloud
LIBS += C:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/mdsplib/lib/libmdsp.lib
#LIBS += -L../../ExternalLib/mdsplib/lib -llibmdsp
