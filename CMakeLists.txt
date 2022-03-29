cmake_minimum_required(VERSION 3.21)
project(PujakEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(PujakEngine main.cpp)
target_link_libraries(PujakEngine -lOpenGL32 -lfreeGLUT)
