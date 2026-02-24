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

int check_output(int input, const char *expected, int test_number)
{
  FILE *fp;
  char buffer[256];
  char cmd[128];

  sprintf(cmd, "echo %d | %s", input, MAIN_CMD);
  fp = POPEN(cmd, "r");
  if (!fp)
    return 0;

  if (!fgets(buffer, sizeof(buffer), fp))
  {
    PCLOSE(fp);
    printf("Test %d failed (no output)\n", test_number);
    return 0;
  }
  PCLOSE(fp);

  buffer[strcspn(buffer, "\r\n")] = 0;

  if (strcmp(buffer, expected) == 0)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %s; got: %s)\n", test_number, expected, buffer);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output(0, "night", 1);
  passed += check_output(21600, "morning", 2);
  passed += check_output(43200, "day", 3);
  passed += check_output(64800, "evening", 4);
  passed += check_output(86399, "evening", 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
