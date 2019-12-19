#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP  20

float fahr_to_celsius(float fahr);

int main() {
  float fahr;
  float celsius;
  printf("Fahr\tCelsius\n");
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    celsius = fahr_to_celsius(fahr);
    printf("%4.0f\t%7.1f\n", fahr, celsius);
  }

  return 0;
}

float fahr_to_celsius(float fahr) {
  return 5.0 / 9.0 * (fahr - 32.0);
}
