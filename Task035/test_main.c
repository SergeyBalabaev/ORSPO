#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
#define MAIN_CMD "main.exe"
#else
#define MAIN_CMD "./main"
#endif

int check_output(const char *args, int expected, int test_number)
{
  char cmd[256];
  sprintf(cmd, "%s %s", MAIN_CMD, args);

  FILE *fp = popen(cmd, "r");
  if (!fp)
    return 0;

  int result;
  if (fscanf(fp, "%d", &result) != 1)
  {
    pclose(fp);
    printf("Test %d failed (invalid output)\n", test_number);
    return 0;
  }

  pclose(fp);

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

  passed += check_output("1 2 3", 6, 1);
  passed += check_output("10 20 30 40", 100, 2);
  passed += check_output("-1 -2 -3", -6, 3);
  passed += check_output("42", 42, 4);
  passed += check_output("", 0, 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
