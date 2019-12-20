#include <stdio.h>

#define TABSIZE 8

int main() {
  int c, i;
  int pos = 1;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (i = pos; i <= TABSIZE; ++i) {
        putchar(' ');
      }
      pos = 1;
    } else if (c == '\n') {
      putchar(c);
      pos = 1;
    } else {
      putchar(c);
      if (pos == 8) {
        pos = 1;
      } else {
        ++pos;
      }
    }
  }

  return 0;
}
