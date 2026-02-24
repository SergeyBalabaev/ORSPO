#include <stdio.h>
#include "resistance.h"

int main() {
    double r1 = 100.0;
    double r2 = 200.0;
    
    double result = parallel_resistance(&r1, &r2);
    printf("Parallel resistance of %.2f and %.2f is %.2f ohms\n", r1, r2, result);
    
    r2 = 0.0;
    result = parallel_resistance(&r1, &r2);
    printf("Parallel resistance of %.2f and %.2f is %.2f ohms\n", r1, r2, result);
    
    r2 = -50.0;
    result = parallel_resistance(&r1, &r2);
    printf("Parallel resistance of %.2f and %.2f is %.2f ohms\n", r1, r2, result);
    
    return 0;
}