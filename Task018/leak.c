#include <stdio.h>
#include <stdlib.h>

void create_leak() {
    int *arr = (int*)malloc(10 * sizeof(int));
    // Забыли освободить память!
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    printf("Array created, but not freed\n");
}

void use_uninitialized() {
    int *ptr = (int*)malloc(sizeof(int));
    // Используем неинициализированную память
    if (*ptr > 0) {
        printf("Value is positive\n");
    }
    free(ptr);
}

void write_out_of_bounds() {
    int *arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i <= 5; i++) { // Ошибка: выход за границы при i=5
        arr[i] = i * 10;
    }
    free(arr);
}

int main() {
    printf("=== Valgrind Demo ===\n");
    
    create_leak();
    use_uninitialized();
    write_out_of_bounds();
    
    printf("Program finished\n");
    return 0;
}