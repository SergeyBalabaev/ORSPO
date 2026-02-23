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

  char output[500];
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

  passed += check_output(
      "5\nbanana apple cherry date apricot",
      "apple apricot banana cherry date", 1);

  passed += check_output(
      "3\nDog Cat Mouse",
      "Cat Dog Mouse", 2);

  passed += check_output(
      "4\nzebra apple lion cat",
      "apple cat lion zebra", 3);

  passed += check_output(
      "0",
      "", 4);

  passed += check_output(
      "1\nsingle",
      "single", 5);

  printf("\nSummary: Passed %d/5 tests\n", passed);
  return 0;
}
