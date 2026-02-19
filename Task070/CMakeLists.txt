cmake_minimum_required(VERSION 3.10)
project(Task070)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIR})

add_executable(verify_task070 verify_task070.cpp task070.hpp)
target_link_libraries(verify_task070 PRIVATE gtest gtest_main)
