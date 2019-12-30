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
  int n;
  for (n = 0; *s != '\0'; s++) {
    ++n;
  }
  return n;
}
