project (RayTracer)

include_directories(
    ${CollisionDetection_SOURCE_DIR}
    ${Geometry_SOURCE_DIR}
    ${Math_SOURCE_DIR}
    ${Materials_SOURCE_DIR}
    )

set(HEADERS
    Camera.h
    RayTracer.h
    )

set(SOURCES
    Camera.cpp
    RayTracer.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    CollisionDetection
    Math
    Materials
    )

add_dependencies(${PROJECT_NAME}
    CollisionDetection
    Materials
    Math)
