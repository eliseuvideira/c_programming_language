#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP  20

float fahr_to_celsius(float fahr);

int main() {
  float fahr;
  printf("fahr\tcelsius\n");
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%4.0f\t%7.1f\n", fahr, fahr_to_celsius(fahr));
  }
}

float fahr_to_celsius(float fahr) {
  return 5.0 / 9.0 * (fahr - 32.0);
}
