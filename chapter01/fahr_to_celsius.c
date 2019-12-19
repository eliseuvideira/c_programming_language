#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 100;
  step = 20;

  celsius = lower;
  while (celsius <= upper) {
    fahr = 9.0 * celsius / 5.0 + 32;
    printf("%6.0f\t%4.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
