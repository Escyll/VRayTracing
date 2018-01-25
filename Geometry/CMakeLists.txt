project (Geometry)

include_directories(
    ${Math_SOURCE_DIR}
    )

set(HEADERS
    Triangle.h
    )

set(SOURCES
    Triangle.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
