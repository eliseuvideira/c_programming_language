#include <stdio.h>

int getch();
void ungetch(int);

char buf = 0;

int getch() {
  int c;

  if (buf != 0) {
    c = buf;
  } else {
    c = getchar();
  }

  buf = 0;

  return c;
}

void ungetch(int c) {
  if (buf != 0) {
    printf("ungetch: there's already one character\n");
  } else {
    buf = c;
  }
}

