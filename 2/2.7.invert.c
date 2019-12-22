#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void print_binary(unsigned x);

int main() {
  int x = 610;

  print_binary(x);
  print_binary(invert(x, 5, 5));

  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}

void print_binary(unsigned x) {
  int i, j;
  for (i = 31; i >= 0; i--) {
    j = x >> i;
    if (j & 1) {
      putchar('1');
    } else {
      putchar('0');
    }
  }
  putchar('\n');
}
