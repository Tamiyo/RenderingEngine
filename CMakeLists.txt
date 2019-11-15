cmake_minimum_required(VERSION 3.1.0)
project(RenderEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_subdirectory(fmt EXCLUDE_FROM_ALL)

add_executable(RenderEngine main.cpp shapes/shape.h primitives/geometry.h primitives/linmath.h shapes/sphere.h algorithm/raytracing.h film/color.h film/camera.h materials/material.h algorithm/bundle.h algorithm/random.h shapes/triangle.h importer/collada.h rapidxml/rapidxml.hpp rapidxml/rapidxml_iterators.hpp rapidxml/rapidxml_print.hpp rapidxml/rapidxml_utils.hpp)

target_link_libraries(RenderEngine PRIVATE fmt::fmt-header-only)