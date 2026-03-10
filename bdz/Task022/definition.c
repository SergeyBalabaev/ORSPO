#include <stdio.h>

int main()
{
    const int x = 10;                   //константная переменная
    //x = 15;     //-

    int * ptr;                          //указатель
    *ptr = 0;       //+
    ptr = NULL;     //+

    int const * ptrToConst;             //указатель на константу
    *ptrToConst = 0;        //-
    ptrToConst = NULL;      //+

    int * const constPtr;               //константный указатель
    *constPtr = 0;          //+
    constPtr = NULL;        //-

    int const * const constPtrToConst;  //константный указатель на константу
    *constPtrToConst = 0;   //-
    constPtrToConst = NULL; //-

    int var = 20;
    scanf("%d", &var);
    const int n = var;
    constexpr int n = var;

}