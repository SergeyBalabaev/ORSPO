cmake_minimum_required(VERSION 3.10)
project(Task062)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIR})

add_executable(verify_task062 verify_task062.cpp task062.hpp)
target_link_libraries(verify_task062 PRIVATE gtest gtest_main)
