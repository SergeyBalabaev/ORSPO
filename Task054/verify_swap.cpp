#include <limits>

#include <gtest/gtest.h>

#include "swap.hpp"

TEST(Test, Int) {
    int a = 5;
    int b = 10;

    swap(&a, &b);

    EXPECT_EQ(a, 10);
    EXPECT_EQ(b, 5);
}

TEST(Test, Bytes) {
    int a = 71;
    char b = 'C';
    swap(&a, &b);
    EXPECT_EQ(a, 'C');
    EXPECT_EQ(b, 71);
}

TEST(Test, MemorySize) {
    #pragma pack(push, 1)
    struct firstType {
        unsigned long long value;
    };

    struct secondType {
        int value1;
        int value2;
    };
    #pragma pack(pop)

    static_assert(sizeof(unsigned long long) == (2 * sizeof(int)), "Types have different sizes");
    static_assert(sizeof(firstType) == sizeof(secondType), "Structs have different sizes");

    firstType a{std::numeric_limits<unsigned long long>::max()};
    secondType b{0, 0};

    swap(&a, &b);

    EXPECT_EQ(a.value, 0);
    EXPECT_EQ(b.value1, std::numeric_limits<unsigned long long>::max() & 0xFFFFFFFF);
    EXPECT_EQ(b.value2, (std::numeric_limits<unsigned long long>::max() >> 32) & 0xFFFFFFFF);
}
