#include "../Unity/src/unity.h"
#include "max.h"

void test_max_correctaB(void) {
    TEST_ASSERT_EQUAL_INT(3, max(1, 3));
}

void test_max_correctAb(void) {
    TEST_ASSERT_EQUAL_INT(3, max(3, 1));
}

void test_max_correctAB(void) {
    TEST_ASSERT_EQUAL_INT(2, max(2, 2));
}

void test_max_correctab(void) {
    TEST_ASSERT_EQUAL_INT(0, max(-2, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_max_correctaB);
    RUN_TEST(test_max_correctAb);
    RUN_TEST(test_max_correctAB);
    RUN_TEST(test_max_correctab);
    return UNITY_END();
}