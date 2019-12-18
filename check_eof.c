#include <stdio.h>

int main() {
  int c;

  c = getchar();
  printf("%d\n", c == EOF);

  return 0;
}
