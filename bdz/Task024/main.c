#include <stdio.h>
#include "max.h"

int main(void)
{
  int a, b;

  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  int result = max(a, b);

  printf("Max: %d\n", result);

  return 0;
}
