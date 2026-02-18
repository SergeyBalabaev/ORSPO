#include <stdio.h>

int main() {
#ifdef _WIN64
    printf("Running on Windows!\n");
#else
    printf("Running on Linux/Unix!\n");
#endif
    return 0;
}