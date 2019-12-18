#include <stdio.h>

#define TABSIZE 2

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    int i;
    if (c == '\t') {
      for (i = 0; i < TABSIZE; ++i) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }

  return 0;
}
