cmake_minimum_required(VERSION 3.10)
project(Task061)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIR})

add_executable(verify_task061 verify_task061.cpp task061.hpp)
target_link_libraries(verify_task061 PRIVATE gtest gtest_main)
