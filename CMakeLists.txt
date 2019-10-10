cmake_minimum_required(VERSION 3.8)
project(IZ1)

set (CMAKE_CXX_STANDARD 11)


add_subdirectory(lib/)
include_directories(lib/googletest/include)
include_directories(headers/)


add_executable(IZ1 main.c reduction.c)
add_executable(Gtest gtest.cpp reduction.c)

target_link_libraries(Gtest gtest gtest_main)

