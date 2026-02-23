#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#define MAIN_CMD "main.exe"
#else
#define POPEN popen
#define PCLOSE pclose
#define MAIN_CMD "./main"
#endif

int check_output(int a, int b, int c, int expected, int test_number)
{
  FILE *fp;
  int result;
  char cmd[128];

  sprintf(cmd, "echo %d %d %d | %s", a, b, c, MAIN_CMD);
  fp = POPEN(cmd, "r");
  if (!fp)
    return 0;

  if (fscanf(fp, "%d", &result) != 1)
  {
    PCLOSE(fp);
    printf("Test %d failed (invalid output)\n", test_number);
    return 0;
  }
  PCLOSE(fp);

  if (result == expected)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %d; got: %d)\n", test_number, expected, result);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output(1, 2, 3, 1, 1);
  passed += check_output(10, 5, 7, 5, 2);
  passed += check_output(-1, 0, 1, -1, 3);
  passed += check_output(5, 5, 10, 5, 4);
  passed += check_output(7, 7, 7, 7, 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
