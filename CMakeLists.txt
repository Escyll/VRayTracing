cmake_minimum_required (VERSION 3.7)
project (VRayTracing)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib )
set( LIBRARIES "${CMAKE_SOURCE_DIR}/Libraries")

add_subdirectory(App)
add_subdirectory(Math)
add_subdirectory(Geometry)
add_subdirectory(CollisionDetection)
add_subdirectory(RayTracer)
add_subdirectory(GlWindowRenderer)
