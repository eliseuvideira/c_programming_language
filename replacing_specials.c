#include <stdio.h>

int main() {
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
      case '\\':
        putchar('\\');
        putchar('\\');
      default:
        putchar(c);
        break;
    }
  }

  return 0;
}
