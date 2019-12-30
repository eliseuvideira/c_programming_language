#include <stdio.h>

int main() {
  double value;
  int get_float(double *);

  while (get_float(&value) != EOF) {
    printf("%19.8f\n", value);
  }

  return 0;
}

