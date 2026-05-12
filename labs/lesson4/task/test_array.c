#include "../../../bdz/Unity/src/unity.h"
#include "array.h"
#include <stdlib.h>

#define SIZE 10
#define MAX_VALUE 100

/*Проверка корректности сортировки массива с неупорядоченными элементами*/
void test_bubble_sort_sorted(void)
{ 
    ///
}

/*Проверка сохранения порядка элементов в уже отсортированном массиве*/
void test_bubble_sort_already_sorted(void)
{
    ///
}

/*Проверка корректности сортировки массива, упорядоченного по убыванию*/
void test_bubble_sort_reverse(void)
{
    ///
}

/*Проверка генерации элементов массива в допустимом диапазоне значений*/
void test_fill_array_range(void)
{
    ///
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_bubble_sort_sorted);
    RUN_TEST(test_bubble_sort_already_sorted);
    RUN_TEST(test_bubble_sort_reverse);
    RUN_TEST(test_fill_array_range);

    return UNITY_END();
}