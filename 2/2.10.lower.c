#include <stdio.h>

char lower(char c);

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    putchar(lower(c));
  }

  return 0;
}

char lower(char c) {
  return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}
