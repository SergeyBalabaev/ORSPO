#include <stdio.h>
#include <float.h>
#include <math.h>

void demonstrate_precision_limits() {
    printf("=== Пределы точности ===\n");
    printf("float:\n");
    printf("  FLT_DIG = %d (количество десятичных цифр точности)\n", FLT_DIG);
    printf("  FLT_EPSILON = %.10e (минимальное x такое, что 1.0 + x != 1.0)\n", FLT_EPSILON);
    printf("  FLT_MIN = %.10e\n", FLT_MIN);
    printf("  FLT_MAX = %.10e\n\n", FLT_MAX);
    
    printf("double:\n");
    printf("  DBL_DIG = %d\n", DBL_DIG);
    printf("  DBL_EPSILON = %.10e\n", DBL_EPSILON);
    printf("  DBL_MIN = %.10e\n", DBL_MIN);
    printf("  DBL_MAX = %.10e\n\n", DBL_MAX);
}

void demonstrate_epsilon() {
    printf("=== Демонстрация EPSILON ===\n");
    
    float f = 1.0f;
    float f_eps = FLT_EPSILON;
    printf("float: 1.0 + FLT_EPSILON = %.10f\n", f + f_eps);
    printf("float: 1.0 + FLT_EPSILON/2 = %.10f (равно 1.0? %s)\n", 
           f + f_eps/2, (f + f_eps/2 == 1.0f) ? "да" : "нет");
    
    double d = 1.0;
    double d_eps = DBL_EPSILON;
    printf("double: 1.0 + DBL_EPSILON = %.10f\n", d + d_eps);
    printf("double: 1.0 + DBL_EPSILON/2 = %.10f (равно 1.0? %s)\n\n", 
           d + d_eps/2, (d + d_eps/2 == 1.0) ? "да" : "нет");
}

void demonstrate_accumulation_error() {
    printf("=== Накопление ошибки при сложении ===\n");
    
    // Суммирование 0.1 десять раз
    float f_sum = 0.0f;
    double d_sum = 0.0;
    
    printf("Суммирование 0.1 десять раз:\n");
    for (int i = 0; i < 10; i++) {
        f_sum += 0.1f;
        d_sum += 0.1;
    }
    
    printf("float  result: %.20f (ожидалось 1.0)\n", f_sum);
    printf("double result: %.20f\n", d_sum);
    printf("Разница float - double: %.20f\n\n", f_sum - d_sum);
    
    // Суммирование 1e-6 миллион раз
    f_sum = 0.0f;
    d_sum = 0.0;
    
    printf("Суммирование 1e-6 1,000,000 раз:\n");
    for (int i = 0; i < 1000000; i++) {
        f_sum += 1e-6f;
        d_sum += 1e-6;
    }
    
    printf("float  result: %.10f (ожидалось 1.0)\n", f_sum);
    printf("double result: %.10f\n", d_sum);
    printf("Разница float - double: %.10f\n\n", f_sum - d_sum);
}

void demonstrate_catastrophic_cancellation() {
    printf("=== Катастрофическая потеря точности ===\n");
    
    // Квадратное уравнение: x^2 - 10000x + 1 = 0
    float a_f = 1.0f, b_f = -10000.0f, c_f = 1.0f;
    double a_d = 1.0, b_d = -10000.0, c_d = 1.0;
    
    // Дискриминант: D = b^2 - 4ac
    float D_f = b_f * b_f - 4.0f * a_f * c_f;
    double D_d = b_d * b_d - 4.0 * a_d * c_d;
    
    printf("Дискриминант (float): %.15f\n", D_f);
    printf("Дискриминант (double): %.15f\n", D_d);
    
    // Корни: x1 = (-b + sqrt(D)) / (2a), x2 = (-b - sqrt(D)) / (2a)
    float sqrt_D_f = sqrtf(D_f);
    double sqrt_D_d = sqrt(D_d);
    
    float x1_f = (-b_f + sqrt_D_f) / (2.0f * a_f);
    float x2_f = (-b_f - sqrt_D_f) / (2.0f * a_f);
    
    double x1_d = (-b_d + sqrt_D_d) / (2.0 * a_d);
    double x2_d = (-b_d - sqrt_D_d) / (2.0 * a_d);
    
    printf("Корни (float): x1 = %.15f, x2 = %.15f\n", x1_f, x2_f);
    printf("Корни (double): x1 = %.15f, x2 = %.15f\n\n", x1_d, x2_d);
    
    // Проверка: произведение корней должно быть c/a = 1
    printf("Произведение корней (float): %.15f (ожидалось 1.0)\n", x1_f * x2_f);
    printf("Произведение корней (double): %.15f\n\n", x1_d * x2_d);
}

void demonstrate_comparison_problems() {
    printf("=== Проблемы сравнения чисел с плавающей точкой ===\n");
    
    float f1 = 0.1f * 10.0f;
    float f2 = 1.0f;
    
    printf("f1 = 0.1 * 10 = %.20f\n", f1);
    printf("f2 = 1.0 = %.20f\n", f2);
    printf("f1 == f2? %s\n", (f1 == f2) ? "да" : "нет");
    
    // Правильный способ сравнения с допуском
    float epsilon = 1e-6f;
    printf("f1 примерно равно f2 с точностью 1e-6? %s\n\n", 
           (fabsf(f1 - f2) < epsilon) ? "да" : "нет");
}

int main() {
    printf("========================================\n");
    printf("  float vs double: Демонстрация точности\n");
    printf("========================================\n\n");
    
    demonstrate_precision_limits();
    demonstrate_epsilon();
    demonstrate_accumulation_error();
    demonstrate_catastrophic_cancellation();
    demonstrate_comparison_problems();
    
    return 0;
}