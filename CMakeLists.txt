cmake_minimum_required(VERSION 3.10)
project(MathLib)
add_library(mathLib INTERFACE)
target_include_directories(mathLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
