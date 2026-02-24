#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#define MAIN_CMD "main.exe"
#else
#define POPEN popen
#define PCLOSE pclose
#define MAIN_CMD "./main"
#endif

int extract_number(const char *str)
{
  int num;
  if (sscanf(str, "%*[^0123456789-]%d", &num) == 1)
    return num;
  else
    return 0;
}

int check_output(const char *command, int expected, int test_number, int expect_div_zero)
{
  FILE *fp;
  char buffer[256];

  fp = POPEN(command, "r");
  if (!fp)
  {
    printf("Error running test %d\n", test_number);
    return 0;
  }

  fgets(buffer, sizeof(buffer), fp);
  PCLOSE(fp);

  if (strstr(buffer, "Division by zero") || strstr(buffer, "деление на ноль") || strstr(buffer, "Error: Division by zero"))
  {
    if (expect_div_zero)
    {
      printf("Test %d passed\n", test_number);
      return 1;
    }
    else
    {
      printf("Test %d failed (unexpected division by zero)\n", test_number);
      return 0;
    }
  }

  int result = extract_number(buffer);
  if (result == expected)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %d, got: %d)\n", test_number, expected, result);
    return 0;
  }
}

int main(void)
{
  int passed = 0;
  char cmd[128];

  sprintf(cmd, "echo 10 2 | %s", MAIN_CMD);
  passed += check_output(cmd, 5, 1, 0);

  sprintf(cmd, "echo 7 3 | %s", MAIN_CMD);
  passed += check_output(cmd, 2, 2, 0);

  sprintf(cmd, "echo 5 0 | %s", MAIN_CMD);
  passed += check_output(cmd, 0, 3, 1);

  sprintf(cmd, "echo -8 4 | %s", MAIN_CMD);
  passed += check_output(cmd, -2, 4, 0);

  printf("\nSummary: Passed %d/4 tests\n", passed);
  if (passed == 4)
    printf("All tests passed!\n");
  else
    printf("Some tests failed!\n");

  return 0;
}
