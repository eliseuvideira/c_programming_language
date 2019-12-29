#include <stdio.h>

int main() {
  int x = 10;
  int y = 20;
  void swap(int *, int *);

  swap(&x, &y);

  printf("x = %d\ny = %d\n", x, y);

  return 0;
}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

