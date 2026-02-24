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

int check_output(int n, const char *expected[], int count, int test_number)
{
  FILE *fp;
  char line[64];
  char cmd[128];
  sprintf(cmd, "echo %d | %s", n, MAIN_CMD);

  fp = POPEN(cmd, "r");
  if (!fp)
    return 0;

  int passed = 1;
  for (int i = 0; i < count; i++)
  {
    if (!fgets(line, sizeof(line), fp))
    {
      passed = 0;
      break;
    }
    line[strcspn(line, "\r\n")] = 0;
    if (strcmp(line, expected[i]) != 0)
    {
      passed = 0;
      break;
    }
  }

  PCLOSE(fp);

  if (passed)
    printf("Test %d passed\n", test_number);
  else
    printf("Test %d failed\n", test_number);

  return passed;
}

int main(void)
{
  int passed = 0;

  const char *test1[] = {"1", "2", "Fizz", "4", "Buzz"};
  passed += check_output(5, test1, 5, 1);

  const char *test2[] = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};
  passed += check_output(15, test2, 15, 2);

  const char *test3[] = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz", "16", "17", "Fizz", "19", "Buzz"};
  passed += check_output(20, test3, 20, 3);

  const char *test4[] = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz", "16", "17", "Fizz", "19", "Buzz", "Fizz", "22", "23", "Fizz", "Buzz", "26", "Fizz", "28", "29", "FizzBuzz"};
  passed += check_output(30, test4, 30, 4);

  printf("\nSummary: Passed %d/4 tests\n", passed);
  return 0;
}
