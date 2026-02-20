#include <stdio.h>

int main() {
    int value = 42;
    int *ptr = &value;
    int **ptr_to_ptr = &ptr;

    printf("value: %d\n", value);
    printf("*ptr: %d\n", *ptr);
    printf("**ptr_to_ptr: %d\n", **ptr_to_ptr);

    *ptr = 100;
    printf("value = %d\n", value);

    int const *const_ptr = &value;
    // *const_ptr = 50; // Ошибка: нельзя изменить значение через const указатель
    printf("*const_ptr: %d\n", *const_ptr);

    int * const ptr_const = &value;
    // ptr_const = &some_other_var; // Ошибка: нельзя изменить адрес, на который указывает ptr_const
    *ptr_const = 55;
    printf("*ptr_const: %d\n", *ptr_const);

    int *uninitialized;
    printf("%d\n", *uninitialized); // UB: Разыменование сырой памяти

    int *null_ptr = NULL;
    printf("%d\n", *null_ptr); // UB: Разыменование нулевого указателя

    return 0;
}
