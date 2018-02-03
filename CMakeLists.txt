cmake_minimum_required (VERSION 3.7)
project (VRayTracing)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib )
set( LIBRARIES "${CMAKE_SOURCE_DIR}/Libraries")
set (CMAKE_CXX_STANDARD 11)
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMT.lib")
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT.lib")
    endif()
endif()

add_subdirectory(Math)
add_subdirectory(Geometry)
add_subdirectory(Materials)
add_subdirectory(CollisionDetection)
add_subdirectory(RayTracer)
add_subdirectory(GlWindowRenderer)

add_subdirectory(App)
