#include <stdio.h>
#define BUFSIZE 100

int getch();
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int getch() {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

