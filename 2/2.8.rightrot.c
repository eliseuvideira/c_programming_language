#include <stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned shift_right(unsigned x, int length);
void print_binary(unsigned x);
int int_length();

int main() {
  unsigned x = 65535;

  print_binary(x);
  print_binary(rightrot(x, 5));

  return 0;
}

unsigned rightrot(unsigned x, int n) {
  int i, length;
  unsigned value = x;

  length = int_length();

  for (i = 0; i < n; ++i) {
    value = shift_right(value, length);
  }

  return value;
}

unsigned shift_right(unsigned x, int length) {
  return x << length - 1 | (x >> 1);
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

int int_length() {
  int i;
  unsigned v = (unsigned) ~0;
  for (i = 1; (v = v >> 1) > 0; i++);
  return i;
}
