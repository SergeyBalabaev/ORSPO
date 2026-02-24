#include <gtest/gtest.h>
#include "task071.hpp"

TEST(Test, CompareEqual) {
    EXPECT_EQ(compare_strings("hello", "hello"), 0);
    EXPECT_TRUE(is_equal("test", "test"));
}

TEST(Test, CompareGreater) {
    EXPECT_GT(compare_strings("world", "hello"), 0);
    EXPECT_TRUE(is_greater("world", "hello"));
}

TEST(Test, CompareLess) {
    EXPECT_LT(compare_strings("apple", "zebra"), 0);
    EXPECT_TRUE(is_less("apple", "zebra"));
}

TEST(Test, CompareDifferentLengths) {
    EXPECT_LT(compare_strings("abc", "abcd"), 0);
    EXPECT_TRUE(is_less("abc", "abcd"));
}

TEST(Test, CompareCase) {
    EXPECT_GT(compare_strings("Hello", "hello"), 0);
}
