cmake_minimum_required(VERSION 3.10)
project(ORSPO)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest")
set(GTEST_INCLUDE_DIR "${GTEST_DIR}/googletest/include")

add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/gtest_build)

add_subdirectory(example)
add_subdirectory(Task001)
add_subdirectory(Task048)
add_subdirectory(Task049)
add_subdirectory(Task050)
add_subdirectory(Task051)
add_subdirectory(Task052)
add_subdirectory(Task053)

enable_testing()
