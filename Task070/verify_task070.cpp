#include <gtest/gtest.h>
#include "task070.hpp"
#include <cstring>

TEST(Test, ReplaceCharWithTwo) {
    const char* str = "hello";
    char* result = replace_char_with_two(str, 'l', "LL");
    EXPECT_STREQ(result, "heLLeLLo");
    free_string(result);
}

TEST(Test, ReplaceCharNotFound) {
    const char* str = "hello";
    char* result = replace_char_with_two(str, 'x', "XX");
    EXPECT_STREQ(result, "hello");
    free_string(result);
}

TEST(Test, NewStringLength) {
    const char* str = "hello";
    size_t len = new_string_length(str, 'l', "LL");
    EXPECT_EQ(len, 8);
}

TEST(Test, ReplaceMultipleOccurrences) {
    const char* str = "aaa";
    char* result = replace_char_with_two(str, 'a', "bb");
    EXPECT_STREQ(result, "bbbbbbb");
    free_string(result);
}
