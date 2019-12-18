#include <stdio.h>

int power(int base, int exponent);

int main () {
  int i;

  for (i = 0; i < 10; ++i) {
    printf("%6d %6d %6d\n", i, power(2, i), power(-3, i));
  }

  return 0;
}

int power(int base, int exponent) {
  int value;
  for (value = 1; exponent > 0; --exponent) {
    value = value * base;
  }
  return value;
}
