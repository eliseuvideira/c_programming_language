#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8

int main(int argc, char *argv[]) {
  int c, i;
  int tab_size = TABSIZE;
  int pos = 1;

  if (argc > 1) {
    tab_size = atoi(argv[1]);
  }

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (i = pos; i <= tab_size; ++i) {
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
