#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int main()
{
	const size_t n = 100;
	int *arr = (int *)malloc(n * sizeof(int));

	srand(time(NULL));

	fill_array(arr, n);

	printf("Before sorting:\n");
	print_array(arr, n);

	bubble_sort(arr, n);

	printf("After sorting:\n");
	print_array(arr, n);

	free(arr);

	return 0;
}