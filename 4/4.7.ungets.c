#include <stdio.h>
#include <string.h>

int getch();
void ungetch(int);

void ungets(char s[]) {
  int i;
  int len = strlen(s);

  for (i = len - 1; i >= 0; --i) {
    ungetch(s[i]);
  }
}

int main() {
  int c;

  ungets("asdf");

  while ((c = getch()) != EOF) {
    putchar(c);
  }

  return 0;
}

#define BUFSIZE 100

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

