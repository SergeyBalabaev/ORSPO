#include <gtest/gtest.h>

#include <memory>

#include "task055.hpp"

TEST(Test, Intialize) {
    auto arr = std::unique_ptr<int>(initialize(5, 42)); 
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(arr.get()[i], 42);
    }
}

TEST(Test, Deinitialize) {
    auto arr = std::unique_ptr<int>(initialize(5, 42)); 
    deinitialize(arr.get());

    EXPECT_EQ(arr.get(), nullptr);
}

TEST(Test, Reinitialize) {
    auto arr = initialize(5, 42); 
    arr = reinitialize(arr, 10, 84);
    for (size_t i = 0; i < 10; ++i) {
        EXPECT_EQ(arr[i], 84);
    }
    deinitialize(arr);
}

TEST(Test, AddValue) {
    auto arr = initialize(5, 1); 
    add_value(arr, 2, 42);
    EXPECT_EQ(arr[2], 42);
    deinitialize(arr);
}
