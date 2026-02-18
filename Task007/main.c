#include <stdio.h>

struct Empty {

};

int main() {
    int x;
    int y = 10;
    printf("Size: %zu\n", sizeof(struct Empty));
    return 0;
}