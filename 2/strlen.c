#include <stdio.h>

int _strlen(char s[]);

int main() {
  printf("%d\n", _strlen("very long string."));

  return 0;  
}

int _strlen(char s[]) {
  int i = 0;
  while (s[i] != '\0') {
    ++i;
  }
  return i;
}
