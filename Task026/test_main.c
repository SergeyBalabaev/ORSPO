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

int extract_two_numbers(const char *str, int *first, int *second)
{
  int count = 0;
  const char *p = str;
  while (*p && count < 2)
  {
    if (*p == '-' || (*p >= '0' && *p <= '9'))
    {
      int val;
      int n;
      if (sscanf(p, "%d%n", &val, &n) == 1)
      {
        if (count == 0)
          *first = val;
        else
          *second = val;
        count++;
        p += n;
        continue;
      }
    }
    p++;
  }
  return count == 2;
}

int check_output(int input, int expected_hours, int expected_minutes, int test_number)
{
  FILE *fp;
  char buffer[256];
  int hours, minutes;
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

  if (!extract_two_numbers(buffer, &hours, &minutes))
  {
    printf("Test %d failed (could not extract numbers)\n", test_number);
    return 0;
  }

  if (hours == expected_hours && minutes == expected_minutes)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %d hours, %d minutes; got: %d hours, %d minutes)\n",
           test_number, expected_hours, expected_minutes, hours, minutes);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output(0, 0, 0, 1);
  passed += check_output(3661, 1, 1, 2);
  passed += check_output(86399, 23, 59, 3);
  passed += check_output(43200, 12, 0, 4);

  printf("\nSummary: Passed %d/4 tests\n", passed);
  return 0;
}
