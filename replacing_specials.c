#include <stdio.h>

void main() {
  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\t':
        putchar('\\');
        putchar('t');
        break;
      case '\b':
        putchar('\\');
        putchar('b');
        break;
      default:
        putchar(c);
        break;
    }
  }
}
