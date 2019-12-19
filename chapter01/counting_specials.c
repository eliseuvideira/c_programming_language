#include <stdio.h>

int main() {
  int tabs = 0;
  int blanks = 0;
  int lines = 0;
  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\t':
        ++tabs;
        break;
      case ' ':
        ++blanks;
        break;
      case '\n':
        ++lines;
        break;
    }
  }

  printf("tabs: %d\nblanks: %d\nlines: %d\n", tabs, blanks, lines);

  return 0;
}
