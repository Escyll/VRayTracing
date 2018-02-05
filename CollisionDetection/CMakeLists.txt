project (CollisionDetection)

include_directories(
    ${Materials_SOURCE_DIR}
    ${Math_SOURCE_DIR}
    ${Geometry_SOURCE_DIR}
    )

set(HEADERS
    BoxCollidable.h
    Collidable.h
    TriangleCollidable.h
    )

set(SOURCES
    BoxCollidable.cpp
    TriangleCollidable.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    Math
    Geometry
    )

add_dependencies(${PROJECT_NAME}
    Math
    Geometry)
