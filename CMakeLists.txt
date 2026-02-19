cmake_minimum_required(VERSION 3.10)
project(ORSPO)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest")
set(GTEST_INCLUDE_DIR "${GTEST_DIR}/googletest/include")

add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/gtest_build)
add_subdirectory(example)
add_subdirectory(Task001)

enable_testing()
