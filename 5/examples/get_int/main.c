#include <stdio.h>

int main() {
  int value;
  int get_int(int *);

  while (get_int(&value) != EOF) {
    printf("%d\n", value);
  }

  return 0;
}

