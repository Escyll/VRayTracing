project (Materials)

include_directories(
    ${Math_SOURCE_DIR}
    )

set(HEADERS
    Material.h
    Color.h
    Diffuse.h
    )

set(SOURCES
    Color.cpp
    Diffuse.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
