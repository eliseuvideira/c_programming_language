#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  unsigned x, y;

  x = 16;
  y = 1;

  printf("%u\n", setbits(x, 0, 1, y));

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}
