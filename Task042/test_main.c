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

  char output[200];
  if (!fgets(output, sizeof(output), fp))
  {
    pclose(fp);
    remove("tmp_input.txt");
    if (expected[0] == '\0')
    {
      printf("Test %d passed\n", test_number);
      return 1;
    }
    printf("Test %d failed (no output)\n", test_number);
    return 0;
  }

  output[strcspn(output, "\n")] = 0;

  pclose(fp);
  remove("tmp_input.txt");

  if (strcmp(output, expected) == 0)
  {
    printf("Test %d passed\n", test_number);
    return 1;
  }
  else
  {
    printf("Test %d failed (expected: '%s'; got: '%s')\n", test_number, expected, output);
    return 0;
  }
}

int main(void)
{
  int passed = 0;

  passed += check_output("8\n1 1 2 2 2 3 3 4", "1 2 3 4", 1);
  passed += check_output("5\n5 5 5 5 5", "5", 2);
  passed += check_output("6\n1 2 3 4 5 6", "1 2 3 4 5 6", 3);
  passed += check_output("0", "", 4);
  passed += check_output("4\n1 1 1 1", "1", 5);
  passed += check_output("7\n2 2 3 3 3 2 2", "2 3 2", 6);

  printf("\nSummary: Passed %d/6 tests\n", passed);
  return 0;
}
