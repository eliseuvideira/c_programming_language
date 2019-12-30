#include <stdio.h>

int main() {
  int x;
  void _strncpy(char *, char *, int);
  void _strncat(char *, char *, int);
  int _strncmp(char *, char *, int);

  char s[100] = "Hello World";
  char t[100] = "C Programming Language";
  _strncpy(s, t, 5);
  printf("%s\n", s);
  printf("%s\n", t);

  _strncat(s, "Programming Language", 10);
  printf("%s\n", s);
  printf("%s\n", t);

  x = _strncmp(s, t, 5);
  printf("%d\n", x);

  _strncpy(t, s, 5);
  x = _strncmp(s, t, 5);
  printf("%d\n", x);

  return 0;
}

