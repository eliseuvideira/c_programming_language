#include <stdio.h>

int string_length(char *);

int main() {
  char s[] = "variable";
  char *ps;

  ps = &s[2];

  printf("%d\n", string_length("hello world"));
  printf("%d\n", string_length(s));
  printf("%d\n", string_length(ps));

  return 0;
}

int string_length(char *s) {
  char *p = s;
  while (*p != '\0') {
    ++p;
  }

  return p - s;
}
