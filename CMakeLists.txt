cmake_minimum_required(VERSION 3.1.0)
project(RenderEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_subdirectory(fmt EXCLUDE_FROM_ALL)

add_executable(RenderEngine main.cpp geometry/3d/vector3.h geometry/2d/point2.h geometry/3d/point3.h geometry/2d/vector2.h geometry/base/base.h)

target_link_libraries(RenderEngine PRIVATE fmt::fmt-header-only)