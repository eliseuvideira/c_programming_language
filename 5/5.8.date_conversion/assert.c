#include <stdio.h>
#include <stdlib.h>

void assert_equals(int received, int expected) {
  if (received != expected) {
    printf("error: assert_equals failed, expected %d, got %d\n", received, expected);
    exit(1);
  }
}

