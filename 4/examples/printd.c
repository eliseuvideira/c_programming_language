#include <stdio.h>
#include <limits.h>

void printd(int d);

int main() {
  int d = SHRT_MAX;

  printd(d);

  return 0;
}

void printd(int d) {
  if (d < 0) {
    putchar('-');
    d = -d;
  }
  if (d / 10) {
    printd(d / 10);
  }
  putchar(d % 10 + '0');
}

