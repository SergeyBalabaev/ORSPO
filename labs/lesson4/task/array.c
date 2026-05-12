#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define MAX_VALUE 100

void fill_array(int *arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % MAX_VALUE;
	}
}

void print_array(const int *arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubble_sort(int *arr, size_t size)
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
