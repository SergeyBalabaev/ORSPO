#include <stdio.h>

int main() {
    int a[5] = {10,20,30,40,50};
    int *p = a;

    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));

    p = p + 3;
    printf("%d\n", *p);

    return 0;
}
