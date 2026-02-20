#include "../../Unity/src/unity.h"
#include "../src/resistance.h"
#include <math.h>

#define EPSILON 0.000001

void test_parallel_normal_values(void) {
    double r1 = 100.0;
    double r2 = 200.0;
    double expected = (100.0 * 200.0) / (100.0 + 200.0); // 66.666...
    double result = parallel_resistance(&r1, &r2);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, expected, result);
}

void test_parallel_equal_values(void) {
    double r1 = 150.0;
    double r2 = 150.0;
    double expected = 75.0;  // (150*150)/(150+150) = 22500/300 = 75
    double result = parallel_resistance(&r1, &r2);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, expected, result);
}

void test_parallel_one_zero(void) {
    double r1 = 100.0;
    double r2 = 0.0;
    double expected = 0.0;  // Короткое замыкание
    double result = parallel_resistance(&r1, &r2);
    TEST_ASSERT_EQUAL_DOUBLE(expected, result);
}

void test_parallel_both_zero(void) {
    double r1 = 0.0;
    double r2 = 0.0;
    double expected = 0.0;
    double result = parallel_resistance(&r1, &r2);
    TEST_ASSERT_EQUAL_DOUBLE(expected, result);
}

void test_parallel_very_large(void) {
    double r1 = 1e6;   // 1 МОм
    double r2 = 1e6;   // 1 МОм
    double expected = 500000.0;  // 500 кОм
    double result = parallel_resistance(&r1, &r2);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON * 1e6, expected, result);
}

void test_parallel_null_pointer(void) {
    double r1 = 100.0;
    // Проверка с NULL указателем (ожидаем 0 и сообщение об ошибке в stderr)
    double result = parallel_resistance(NULL, &r1);
    TEST_ASSERT_EQUAL_DOUBLE(0.0, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_parallel_normal_values);
    RUN_TEST(test_parallel_equal_values);
    RUN_TEST(test_parallel_one_zero);
    RUN_TEST(test_parallel_both_zero);
    RUN_TEST(test_parallel_very_large);
    RUN_TEST(test_parallel_null_pointer);
    return UNITY_END();
}