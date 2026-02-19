#include <gtest/gtest.h>
#include "task073.hpp"
#include <cstring>

TEST(Test, ConcatenateStrings) {
    char* result = concatenate_strings("Hello", " World");
    EXPECT_STREQ(result, "Hello World");
    free_string(result);
}

TEST(Test, ConcatenateEmpty) {
    char* result = concatenate_strings("", "test");
    EXPECT_STREQ(result, "test");
    free_string(result);
    
    result = concatenate_strings("test", "");
    EXPECT_STREQ(result, "test");
    free_string(result);
}

TEST(Test, ConcatenatedLength) {
    size_t len = concatenated_length("hello", "world");
    EXPECT_EQ(len, 10);
}

TEST(Test, AppendString) {
    char buffer[100] = "Hello";
    append_string(buffer, " World", 100);
    EXPECT_STREQ(buffer, "Hello World");
}

TEST(Test, LongStrings) {
    char* result = concatenate_strings("The quick brown ", "fox jumps");
    EXPECT_STREQ(result, "The quick brown fox jumps");
    free_string(result);
}
