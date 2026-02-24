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

int check_output(const char *input, const char *expected, int test_number)
{
  FILE *fp;
  char result[128];
  char cmd[256];

  sprintf(cmd, "echo %s | %s", input, MAIN_CMD);
  fp = POPEN(cmd, "r");
  if (!fp)
    return 0;

  if (!fgets(result, sizeof(result), fp))
  {
    PCLOSE(fp);
    printf("Test %d failed (no output)\n", test_number);
    return 0;
  }
  PCLOSE(fp);

  result[strcspn(result, "\r\n")] = 0;

  if (strcmp(result, expected) == 0)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %s; got: %s)\n", test_number, expected, result);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output("abba", "Yes", 1);
  passed += check_output("abcba", "Yes", 2);
  passed += check_output("abcd", "No", 3);
  passed += check_output("a", "Yes", 4);
  passed += check_output("aa", "Yes", 5);
  passed += check_output("ab", "No", 6);

  printf("\nSummary: Passed %d/6 tests\n", passed);
  return 0;
}
