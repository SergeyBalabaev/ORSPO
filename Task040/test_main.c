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

  char output[100];
  if (!fgets(output, sizeof(output), fp))
  {
    pclose(fp);
    remove("tmp_input.txt");
    printf("Test %d failed (no output)\n", test_number);
    return 0;
  }

  // Убираем \n
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

  passed += check_output("5\n1 3 2 3 5", "Duplicate: 3", 1);
  passed += check_output("4\n1 2 3 4", "No duplicates", 2);
  passed += check_output("6\n5 1 5 2 2 3", "Duplicate: 5", 3);
  passed += check_output("3\n10 20 10", "Duplicate: 10", 4);
  passed += check_output("1\n42", "No duplicates", 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
