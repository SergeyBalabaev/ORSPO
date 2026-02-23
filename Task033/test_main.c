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

  passed += check_output("3\n1 2 3", 2.0, 1);
  passed += check_output("4\n4 5 6 7", 5.5, 2);
  passed += check_output("5\n-1 0 1 2 3", 1.0, 3);
  passed += check_output("1\n42", 42.0, 4);
  passed += check_output("6\n1 1 1 1 1 1", 1.0, 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
