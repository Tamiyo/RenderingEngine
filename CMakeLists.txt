cmake_minimum_required(VERSION 3.1.0)
project(RenderEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_subdirectory(fmt EXCLUDE_FROM_ALL)

add_executable(RenderEngine main.cpp shapes/shape.h primitives/geometry.h primitives/linmath.h shapes/sphere.h algorithm/raytracing.h film/color.h main2.cpp film/camera.h)

target_link_libraries(RenderEngine PRIVATE fmt::fmt-header-only)