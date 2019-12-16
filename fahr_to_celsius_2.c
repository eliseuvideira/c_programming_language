#include <stdio.h>

void main() {
  int fahr;
  printf("fahr\tcelsius\n");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%4d\t%7.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
  }
}
