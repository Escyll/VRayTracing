project (Math)

set(HEADERS
    Point.h
    Ray.h
    Vector.h
    Quaternion.h
    )

set(SOURCES 
    Point.cpp
    Ray.cpp
    Vector.cpp
    Quaternion.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
