cmake_minimum_required(VERSION 3.10)
project(Task073)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIR})

add_executable(verify_task073 verify_task073.cpp task073.hpp)
target_link_libraries(verify_task073 PRIVATE gtest gtest_main)
