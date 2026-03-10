#include <stdio.h>
#include <errno.h>
#include <math.h>

int main(void) {
    double x = sqrt(-1.0);
    if (errno != 0) {
        printf("Ошибка: %d\n", errno);
        perror("sqrt");
    }
    perror("Всё не хорошо :( ");
    printf("Всё хорошо :)\n");
    return 0;
}


