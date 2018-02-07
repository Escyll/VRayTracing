project (RayTracer)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

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
