#include <gtest/gtest.h>
#include "task072.hpp"
#include <cstring>

TEST(Test, ConvertToUppercase) {
    char str[] = "hello";
    convert_to_uppercase(str);
    EXPECT_STREQ(str, "HELLO");
}

TEST(Test, ConvertToLowercase) {
    char str[] = "HELLO";
    convert_to_lowercase(str);
    EXPECT_STREQ(str, "hello");
}

TEST(Test, ReverseString) {
    char str[] = "hello";
    reverse_in_place(str);
    EXPECT_STREQ(str, "olleh");
}

TEST(Test, ProcessStringWithUppercase) {
    char str[] = "test";
    process_string(str, convert_to_uppercase);
    EXPECT_STREQ(str, "TEST");
}

TEST(Test, MixedCase) {
    char str[] = "HeLLo WoRLd";
    convert_to_lowercase(str);
    EXPECT_STREQ(str, "hello world");
}
