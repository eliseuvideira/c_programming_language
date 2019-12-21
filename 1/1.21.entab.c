#include <stdio.h>

#define TABSIZE 8

int main() {
  int c, i;
  int blanks = 0;
  int pos = 0;

  while ((c = getchar()) != EOF) {
    ++pos;
    if (c == ' ') {
      if (pos == TABSIZE) {
        blanks = 0;
        pos = 0;
        putchar('\t');
      } else {
        ++blanks;
      }
    } else if (c == '\n') {
      putchar(c);
      pos = 0;
      blanks = 0;
    } else {
      if (blanks > 0) {
        while (blanks > 0) {
          putchar(' ');
          --blanks;
        }
      }
      putchar(c);
      pos = 0;
    }
  }

  return 0;
}