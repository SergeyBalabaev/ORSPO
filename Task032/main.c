#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s)
{
  // Enter your code
}

int main(void)
{
  char s[101];
  scanf("%100s", s);
  if (is_palindrome(s))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
