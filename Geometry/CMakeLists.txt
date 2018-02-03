project (Geometry)

include_directories(
    ${Math_SOURCE_DIR}
    )

set(HEADERS
    Box.h
    Triangle.h
    )

set(SOURCES
    Box.cpp
    Triangle.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

add_dependencies(${PROJECT_NAME}
    Math)
