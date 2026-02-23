#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define MAIN_CMD "main.exe"
#else
#define MAIN_CMD "./main"
#endif

int check_output(const char *input, int sum, int test_number)
{
  FILE *fp_input = fopen("tmp_input.txt", "w");
  if (!fp_input)
    return 0;
  fprintf(fp_input, "%s\n", input);
  fclose(fp_input);

  FILE *fp = popen(MAIN_CMD " < tmp_input.txt", "r");
  if (!fp)
    return 0;

  int rsum;
  if (fscanf(fp, "Sum: %d", &rsum) != 1)
  {
    pclose(fp);
    remove("tmp_input.txt");
    printf("Test %d failed (invalid output)\n", test_number);
    return 0;
  }

  pclose(fp);
  remove("tmp_input.txt");

  if (rsum == sum)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: %d; got: %d)\n", test_number, sum, rsum);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output("5\n1 3 5 7 9", 25, 1);
  passed += check_output("3\n-1 0 1", 0, 2);
  passed += check_output("4\n10 20 30 40", 100, 3);
  passed += check_output("6\n5 5 5 5 5 5", 30, 4);
  passed += check_output("1\n42", 42, 5);
  passed += check_output("2\n-10 10", 0, 6);
  passed += check_output("0\n", 0, 7);

  printf("\nSummary: Passed %d/7 tests\n", passed);
  return 0;
}
