#include "calc.h"
#include <stdio.h>

int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) { 
        sum += arr[i];
    }
    return sum;
}

int divide(int a, int b) {
    return a * b;
}


