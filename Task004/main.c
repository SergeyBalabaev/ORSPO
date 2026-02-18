#include <stdio.h>

#define X 10

int summ(int x, int y)
{
    return x + y;
}
int mult(int x, int y) //comment
{
    return x * y;
}

int main()
{
    printf("Sum = %d\n", summ(X,5));
    printf("Mult = %d\n", mult(5,5));
    return 0;
}
