project (CollisionDetection)

include_directories(
    ${Math_SOURCE_DIR}
    ${Geometry_SOURCE_DIR}
    )

set(HEADERS
    RayCollider.h
    )

set(SOURCES
    RayCollider.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
