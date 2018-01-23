QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Math/release/ -lMath
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Math/debug/ -lMath

INCLUDEPATH += $$PWD/../../Math
DEPENDPATH += $$PWD/../../Math

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Math/release/libMath.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Math/debug/libMath.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Math/release/Math.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Math/debug/Math.lib

SOURCES +=  \
    TestVector.cpp
HEADERS += \
    TestVector.h
