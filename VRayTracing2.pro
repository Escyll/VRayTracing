TEMPLATE = subdirs

SUBDIRS += \
    App \
    Math \
    Geometry \
    Tests \
    CollisionDetection \
    glWindowRenderer \
    RayTracer

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Geometry/release/ -lGeometry
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Geometry/debug/ -lGeometry

INCLUDEPATH += $$PWD/Geometry
DEPENDPATH += $$PWD/Geometry

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Geometry/release/libGeometry.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Geometry/debug/libGeometry.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Geometry/release/Geometry.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/Geometry/debug/Geometry.lib
