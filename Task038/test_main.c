#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define MAIN_CMD "main.exe"
#else
#define MAIN_CMD "./main"
#endif

int check_output(const char *input, int expected, int test_number)
{
  FILE *fp_input = fopen("tmp_input.txt", "w");
  if (!fp_input)
    return 0;
  fprintf(fp_input, "%s\n", input);
  fclose(fp_input);

  FILE *fp = popen(MAIN_CMD " < tmp_input.txt", "r");
  if (!fp)
    return 0;

  int result;
  if (fscanf(fp, "%d", &result) != 1)
  {
    pclose(fp);
    remove("tmp_input.txt");
    printf("Test %d failed (invalid output)\n", test_number);
    return 0;
  }

  pclose(fp);
  remove("tmp_input.txt");

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
  passed += check_output("5 5 5", 15, 2);
  passed += check_output("-2 7 4", 9, 3);
  passed += check_output("0 0 0", 0, 4);
  passed += check_output("10 -3 2", 9, 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
