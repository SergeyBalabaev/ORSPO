#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define MAIN_CMD "main.exe"
#else
#define MAIN_CMD "./main"
#endif

int extract_percent(const char *output)
{
  const char *p = strstr(output, "Percentage of '");
  if (!p)
    return -1;
  int percent;
  if (sscanf(p, "Percentage of '%*c': %d%%", &percent) != 1)
    return -1;
  return percent;
}

int check_output_percent(const char *input, int test_number)
{
  FILE *fp_input = fopen("tmp_input.txt", "w");
  if (!fp_input)
    return 0;
  fprintf(fp_input, "%s\n", input);
  fclose(fp_input);

  FILE *fp = popen(MAIN_CMD " < tmp_input.txt", "r");
  if (!fp)
    return 0;

  char output[2000];
  size_t len = fread(output, 1, sizeof(output) - 1, fp);
  output[len] = 0;

  pclose(fp);
  remove("tmp_input.txt");

  int percent = extract_percent(output);
  if (percent < 0 || percent > 100)
  {
    printf("Test %d failed (invalid percent)\n", test_number);
    return 0;
  }

  printf("Test %d passed (percentage: %d%%)\n", test_number, percent);
  return 1;
}

int main(void)
{
  int passed = 0;

  passed += check_output_percent("3 4\na", 1);
  passed += check_output_percent("5 5\nk", 2);
  passed += check_output_percent("1 10\nz", 3);

  printf("\nSummary: Passed %d/3 tests\n", passed);
  return 0;
}
