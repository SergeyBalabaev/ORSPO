#include <gtest/gtest.h>

#include "task056.hpp"

TEST(Test2D, Initialize) {
    size_t rows = 3;
    size_t cols = 4;
    int** arr = initialize_2d(rows, cols, 42);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            EXPECT_EQ(arr[i][j], 42);
    deinitialize_2d(arr, rows);
}

TEST(Test2D, Reinitialize) {
    size_t rows = 2;
    size_t cols = 3;
    int** arr = initialize_2d(rows, cols, 42);
    arr = reinitialize_2d(arr, rows, 4, cols, 84);
    for (size_t i = 0; i < 4; ++i)
        for (size_t j = 0; j < cols; ++j)
            EXPECT_EQ(arr[i][j], 84);
    deinitialize_2d(arr, 4);
}

TEST(Test2D, AddValue) {
    size_t rows = 2;
    size_t cols = 2;
    int** arr = initialize_2d(rows, cols, 1);
    add_value_2d(arr, 1, 1, 99);
    EXPECT_EQ(arr[1][1], 99);
    deinitialize_2d(arr, rows);
}
