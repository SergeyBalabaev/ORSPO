#include <stdio.h>

int main() {
    int value = 10;
    int *p1 = &value;
    int *p2 = p1;

    printf("%d\n", *p1);
    printf("%d\n", *p2);

    *p2 = 50;

    printf("%d\n", value);
    printf("%d\n", *p1);
    printf("%d\n", *p2);

    return 0;
}
