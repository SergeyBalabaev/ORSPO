#include "../../Unity/src/unity.h"
#include "../src/sum.h"
#include <limits.h>


void test_sum_normal_values(void) {
    TEST_ASSERT_EQUAL_INT(7, sum(3, 4));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sum_normal_values);
    return UNITY_END();
}
