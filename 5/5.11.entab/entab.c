#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8

int main(int argc, char *argv[]) {
  int c, i;
  int tab_size = TABSIZE;
  int blanks = 0;
  int pos = 0;

  if (argc > 1) {
    tab_size = atoi(argv[1]);
  }

  while ((c = getchar()) != EOF) {
    ++pos;
    if (c == ' ') {
      if (pos == tab_size) {
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

