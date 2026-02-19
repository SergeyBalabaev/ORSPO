#include <gtest/gtest.h>
#include "task074.hpp"

TEST(Test, FindSubstring) {
    const char* str = "hello world";
    int pos = find_substring(str, "world");
    EXPECT_EQ(pos, 6);
}

TEST(Test, SubstringNotFound) {
    const char* str = "hello world";
    int pos = find_substring(str, "xyz");
    EXPECT_EQ(pos, -1);
}

TEST(Test, FindFirstOccurrence) {
    const char* str = "banana";
    int pos = find_first_occurrence(str, "an");
    EXPECT_EQ(pos, 1);
}

TEST(Test, FindLastOccurrence) {
    const char* str = "banana";
    int pos = find_last_occurrence(str, "an");
    EXPECT_EQ(pos, 3);
}

TEST(Test, CountOccurrences) {
    const char* str = "mississippi";
    size_t count = count_occurrences(str, "is");
    EXPECT_EQ(count, 2);
}

TEST(Test, ContainsSubstring) {
    EXPECT_TRUE(contains_substring("hello world", "world"));
    EXPECT_FALSE(contains_substring("hello world", "xyz"));
}
