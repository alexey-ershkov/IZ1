cmake_minimum_required(VERSION 3.8)
project(IZ1)

set (CMAKE_CXX_STANDARD 11)


add_subdirectory(lib/)
include_directories(lib/googletest/include)
include_directories(headers/)


add_executable(IZ1 main.c reduction.c)


enable_testing()

add_executable(Gtest gtest.cpp reduction.c)
target_link_libraries(Gtest gtest gtest_main)
add_test(UnitTest Gtest)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.travis/cmake)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage runUnitTests coverage)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"