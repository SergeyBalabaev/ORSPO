#include <stdio.h>

int main()
{
    int x = 10;
    int * ptrx = &x;
    int * const * const ** const ptrptrx = &ptrx;
    ptrx = NULL;
    *ptrx = NULL;     //менять не можем
    **ptrptrx = 12;     //менять не можем
}