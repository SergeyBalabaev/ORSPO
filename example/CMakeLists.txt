cmake_minimum_required(VERSION 3.10)
project(Example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIR})

add_executable(example main.cpp)
target_link_libraries(example PRIVATE gtest gtest_main)

add_executable(example_verify_test test.cpp)
target_link_libraries(example_verify_test PRIVATE gtest gtest_main)
