#include <gtest/gtest.h>
#include "task068.hpp"
#include <cstring>

TEST(Test, StringLength) {
    const char* str1 = "Hello";
    EXPECT_EQ(string_length(str1), 5);
    
    const char* str2 = "";
    EXPECT_EQ(string_length(str2), 0);
    
    const char* str3 = "Test String";
    EXPECT_EQ(string_length(str3), 11);
}

TEST(Test, InputStringLength) {
    char str[100];
    strcpy(str, "InputTest");
    EXPECT_EQ(string_length(str), 9);
}

TEST(Test, StringCopy) {
    char str1[] = "Original";
    char str2[100];
    strcpy(str2, str1);
    EXPECT_EQ(string_length(str1), string_length(str2));
}
