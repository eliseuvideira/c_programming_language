#include <stdio.h>

int main() {
  char s[1000] = "Recursive reverse function";
  void reverse(char[]);

  reverse(s);

  printf("%s", s);

  return 0;
}

