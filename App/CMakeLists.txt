project (App)

include_directories(
    ${RayTracer_SOURCE_DIR}
    ${Math_SOURCE_DIR}
    ${CollisionDetection_SOURCE_DIR}
    ${Geometry_SOURCE_DIR}
    ${GlWindowRenderer_SOURCE_DIR}
    ${Materials_SOURCE_DIR}
    ${LIBRARIES}/GLFW/include
    ${LIBRARIES}/GLEW/include
    )

link_directories(
    ${LIBRARIES}/GLFW/lib
    ${LIBRARIES}/GLEW/lib/Release/x64/
    )

set(SOURCES
    main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    CollisionDetection
    Geometry
    GlWindowRenderer
    Math
    RayTracer
    Materials
    glfw3.lib
    glew32s.lib
    opengl32.lib
    )
