project (CollisionDetection)

include_directories(
    ${Materials_SOURCE_DIR}
    ${Math_SOURCE_DIR}
    ${Geometry_SOURCE_DIR}
    )

set(HEADERS
    BoxCollidable.h
    Collidable.h
    RayCollider.h
    TriangleCollidable.h
    )

set(SOURCES
    BoxCollidable.cpp
    RayCollider.cpp
    TriangleCollidable.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
