project (Math)

set(HEADERS
    Point.h
    Ray.h
    Vector.h
    )

set(SOURCES 
    Point.cpp
    Ray.cpp
    Vector.cpp
    )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
