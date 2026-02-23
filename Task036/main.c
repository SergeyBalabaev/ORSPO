#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c)
{
  // Enter your code
}

int main(void)
{
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);

  int roots = solve_quadratic(a, b, c);

  if (roots == 0)
    printf("No real roots\n");

  return 0;
}
