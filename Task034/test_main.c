#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef _WIN32
#define MAIN_CMD "main.exe"
#else
#define MAIN_CMD "./main"
#endif

int check_output(const char *input, double expected, int test_number)
{
  FILE *fp_input = fopen("tmp_input.txt", "w");
  if (!fp_input)
    return 0;
  fprintf(fp_input, "%s\n", input);
  fclose(fp_input);

  FILE *fp = popen(MAIN_CMD " < tmp_input.txt", "r");
  if (!fp)
    return 0;

  double result;
  if (fscanf(fp, "%lf", &result) != 1)
  {
    pclose(fp);
    printf("Test %d failed (invalid output)\n", test_number);
    remove("tmp_input.txt");
    return 0;
  }

  pclose(fp);
  remove("tmp_input.txt");

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

  passed += check_output("1 2 5", 9.0, 1);
  passed += check_output("3 3 4", 12.0, 2);
  passed += check_output("10 -2 6", 0.0, 3);
  passed += check_output("5 0 10", 5.0, 4);
  passed += check_output("7 1 1", 7.0, 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
