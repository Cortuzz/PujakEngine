cmake_minimum_required(VERSION 3.21)
project(PujakEngine)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

file(GLOB source_files CONFIGURE_DEPENDS
        "src/primitives/Primitive/Primitive.cpp"
        "src/primitives/Point/Point.cpp"
        "src/primitives/Rect/Rect.cpp"
        "src/primitives/Oval/Oval.cpp"
        )

add_executable(PujakEngine main.cpp ${source_files} )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(PujakEngine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )