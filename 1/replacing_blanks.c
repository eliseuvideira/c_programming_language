#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      putchar(c);
    }
    putchar(c);
  }

  return 0;
}
