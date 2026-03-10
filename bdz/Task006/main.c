#include <stdio.h>
#include <math.h>

int main() {
    double num;
    
    printf("Введите число: ");
    scanf("%lf", &num);
    
    printf("\n=== Результаты вычислений ===\n");
    printf("Квадратный корень: %.3f\n", sqrt(num));
    printf("Синус: %.3f\n", sin(num));
    printf("Косинус: %.3f\n", cos(num));
    printf("Натуральный логарифм: %.3f\n", log(num));
    printf("Экспонента: %.3f\n", exp(num));
    printf("Модуль: %.3f\n", fabs(num));
    
    return 0;
}