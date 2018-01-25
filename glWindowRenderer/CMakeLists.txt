project (GlWindowRenderer)

include_directories(
    ${LIBRARIES}/GLFW/include
    ${LIBRARIES}/GLEW/include
    )

set(HEADERS
    GLWindowRenderer.h
    )

set(SOURCES
    GLWindowRenderer.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
