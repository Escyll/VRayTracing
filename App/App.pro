TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
INCLUDEPATH += \
    ../Libraries/include \
    ../Libraries/GLEW/include
LIBS += -LE:\Escyll\Projects\VRayTracing2\Libraries\GLEW\lib\Release\x64 -lglew32s \
        -LE:\Escyll\Projects\VRayTracing2\Libraries\lib-vc2015 -lglfw3 \
        -lopengl32 -lkernel32 -luser32 -lgdi32 -lshell32

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../glWindowRenderer/release/ -lglWindowRenderer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../glWindowRenderer/debug/ -lglWindowRenderer

INCLUDEPATH += $$PWD/../glWindowRenderer
DEPENDPATH += $$PWD/../glWindowRenderer

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../glWindowRenderer/release/libglWindowRenderer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../glWindowRenderer/debug/libglWindowRenderer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../glWindowRenderer/release/glWindowRenderer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../glWindowRenderer/debug/glWindowRenderer.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../RayTracer/release/ -lRayTracer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../RayTracer/debug/ -lRayTracer

INCLUDEPATH += $$PWD/../RayTracer
DEPENDPATH += $$PWD/../RayTracer

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RayTracer/release/libRayTracer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RayTracer/debug/libRayTracer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RayTracer/release/RayTracer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RayTracer/debug/RayTracer.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CollisionDetection/release/ -lCollisionDetection
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CollisionDetection/debug/ -lCollisionDetection

INCLUDEPATH += $$PWD/../CollisionDetection
DEPENDPATH += $$PWD/../CollisionDetection

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CollisionDetection/release/libCollisionDetection.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CollisionDetection/debug/libCollisionDetection.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CollisionDetection/release/CollisionDetection.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CollisionDetection/debug/CollisionDetection.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Math/release/ -lMath
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Math/debug/ -lMath

INCLUDEPATH += $$PWD/../Math
DEPENDPATH += $$PWD/../Math

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Math/release/libMath.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Math/debug/libMath.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Math/release/Math.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Math/debug/Math.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Geometry/release/ -lGeometry
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Geometry/debug/ -lGeometry

INCLUDEPATH += $$PWD/../Geometry
DEPENDPATH += $$PWD/../Geometry

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Geometry/release/libGeometry.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Geometry/debug/libGeometry.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Geometry/release/Geometry.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Geometry/debug/Geometry.lib
