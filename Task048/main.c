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
    // *const_ptr = 50; // Почему не компилируется?
    printf("*const_ptr: %d\n", *const_ptr);

    int * const ptr_const = &value;
    int other_var = 5;
    // ptr_const = &other_var; // Почему не компилируется?
    *ptr_const = 55;
    printf("*ptr_const: %d\n", *ptr_const);

    int *uninitialized;
    printf("%d\n", *uninitialized);

    int *null_ptr = NULL;
    printf("%d\n", *null_ptr);

    return 0;
}
