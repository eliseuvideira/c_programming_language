#include <stdio.h>

void main() {
  int c;

  c = getchar();
  printf("%d\n", c == EOF);
}
