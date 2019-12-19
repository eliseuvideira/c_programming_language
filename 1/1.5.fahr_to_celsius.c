#include <stdio.h>

int main() {
  int fahr;

  int lower = 0;
  int upper = 300;
  int step = 20;
  
  printf("Fahr\tCelsius\n");
  for (fahr = upper; fahr >= lower; fahr = fahr - step) {
    printf("%4d\t%7.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
  }

  return 0;
}
