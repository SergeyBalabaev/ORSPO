#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define MAIN_CMD "main.exe"
#else
#define MAIN_CMD "./main"
#endif

int check_output(const char *input, const char *expected, int test_number)
{
  FILE *fp_input = fopen("tmp_input.txt", "w");
  if (!fp_input)
    return 0;
  fprintf(fp_input, "%s\n", input);
  fclose(fp_input);

  FILE *fp = popen(MAIN_CMD " < tmp_input.txt", "r");
  if (!fp)
    return 0;

  char result[128];
  if (!fgets(result, sizeof(result), fp))
  {
    pclose(fp);
    remove("tmp_input.txt");
    printf("Test %d failed (no output)\n", test_number);
    return 0;
  }

  pclose(fp);
  remove("tmp_input.txt");

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

  passed += check_output("1 -3 2", "x1 = 2.000000, x2 = 1.000000", 1);
  passed += check_output("1 2 1", "x = -1.000000", 2);
  passed += check_output("1 0 1", "No real roots", 3);
  passed += check_output("0 2 -4", "No real roots", 4);

  printf("\nSummary: Passed %d/4 tests\n", passed);
  return 0;
}
