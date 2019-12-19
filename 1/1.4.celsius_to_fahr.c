#include <stdio.h>

int main() {
  float celsius, fahr;
  
  int lower = 0;
  int upper = 300;
  int step = 20;

  printf("Celsius\tFahr\n");
  for (celsius = lower; celsius <= upper; celsius += step) {
    fahr = celsius * 9.0 / 5.0 + 32.0;
    printf("%7.0f\t%4.0f\n", celsius, fahr);
  }

  return 0;
}
