#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#define MAIN_CMD "main.exe"
#else
#define POPEN popen
#define PCLOSE pclose
#define MAIN_CMD "./main"
#endif

int check_output(int input, double expected, int test_number)
{
  FILE *fp;
  double result;
  char cmd[128];

  sprintf(cmd, "echo %d | %s", input, MAIN_CMD);
  fp = POPEN(cmd, "r");
  if (!fp)
    return 0;

  if (fscanf(fp, "%lf", &result) != 1)
  {
    PCLOSE(fp);
    printf("Test %d failed (invalid output)\n", test_number);
    return 0;
  }
  PCLOSE(fp);

  if (fabs(result - expected) < 1e-6)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %.6f; got: %.6f)\n", test_number, expected, result);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output(0, 6.0 / 1.0, 1);   // 6 / 1 = 6
  passed += check_output(1, 12.0 / 3.0, 2);  // 12 / 3 = 4
  passed += check_output(2, 20.0 / 7.0, 3);  // 20 / 7 ≈ 2.857143
  passed += check_output(-1, 2.0 / 1.0, 4);  // 2 / 1 = 2
  passed += check_output(3, 30.0 / 13.0, 5); // 30 / 13 ≈ 2.307692

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
