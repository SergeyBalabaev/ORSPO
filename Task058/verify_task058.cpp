#include <gtest/gtest.h>

#include "task058.hpp"


TEST(Test, MultiplyByTwo) {
    int arr[5] = {1, 2, 3, 4, 5};
    modify_array(arr, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], 2 * (i + 1));
    }
}

TEST(Test, ZeroArray) {
    int arr[3] = {0, 0, 0};
    modify_array(arr, 3);
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(arr[i], 0);
    }
}