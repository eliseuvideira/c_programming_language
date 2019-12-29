#include <stdio.h>
#include "swap.h"

int main() {
  int x = 10;
  int y = 5;
  swap(int, x, y);

  printf("x = %d\ny = %d\n", x, y);
}

