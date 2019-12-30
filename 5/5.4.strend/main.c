#include <stdio.h>

int main() {
  char s[1000] = "Hello world";
  char t[1000] = "world";
  char u[1000] = "hello";
  int strend(char *, char *);
  void expect_equal(int, int);
  expect_equal(strend(s, t), 1);
  expect_equal(strend(s, u), 0);
  return 0;
}

void expect_equal(int x, int y) {
  if (x != y) {
    printf("error, expected for %d, got %d\n", x, y);
  } else {
    printf("OK\n");
  }
}

