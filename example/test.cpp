#include <gtest/gtest.h>

#include "utility.hpp"

TEST(UtilityTest, IsBool) {
    EXPECT_TRUE(isBool<bool>());
}
