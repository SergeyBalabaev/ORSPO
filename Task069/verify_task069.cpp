#include <gtest/gtest.h>
#include "task069.hpp"
#include <cstring>

TEST(Test, ReplaceChar) {
    char str[] = "hello world";
    replace_char(str, 'o', 'a');
    EXPECT_STREQ(str, "hella warld");
}

TEST(Test, ReplaceCharNotFound) {
    char str[] = "hello";
    replace_char(str, 'x', 'y');
    EXPECT_STREQ(str, "hello");
}

TEST(Test, CountChar) {
    const char* str = "mississippi";
    EXPECT_EQ(count_char(str, 's'), 4);
    EXPECT_EQ(count_char(str, 'i'), 4);
    EXPECT_EQ(count_char(str, 'p'), 2);
    EXPECT_EQ(count_char(str, 'm'), 1);
    EXPECT_EQ(count_char(str, 'x'), 0);
}

TEST(Test, GetCharAt) {
    const char* str = "hello";
    EXPECT_EQ(get_char_at(str, 0), 'h');
    EXPECT_EQ(get_char_at(str, 4), 'o');
    EXPECT_EQ(get_char_at(str, 1), 'e');
}
