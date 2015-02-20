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
INCLUDEPATH += "../../ExternalLib/_xlibs/include/"

#LIBS += -LC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/unittest-cpp_1_4/x64/Debug -lUnitTest++.vsnet2005.debug

LIBS += -L$$TOP_PWD/lib -llibsuncloud
LIBS += C:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/mdsplib/lib/libmdsp.lib
#LIBS += -L$$TOP_PWD/../../ExternalLib/mdsplib/lib -llibmdsp
LIBS += -lQt5Testd

LIBS += -lC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/_xlibs/lib/libboost_thread-vc120-mt-gd-1_57
LIBS += -lC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/_xlibs/lib/libboost_system-vc120-mt-gd-1_57
LIBS += -lC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/_xlibs/lib/libboost_filesystem-vc120-mt-gd-1_57
LIBS += -lC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/_xlibs/lib/libboost_date_time-vc120-mt-gd-1_57
LIBS += -lC:/Users/Sun-Cloud/Documents/Workspace_Qt/ExternalLib/_xlibs/lib/libboost_chrono-vc120-mt-gd-1_57


#RCC_DIR += tests/data/metar

#RESOURCES += $$TOP_PWD/tests/data/metar/metar.csv
