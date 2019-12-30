#include <stdio.h>

int main() {
  char s[1000] = "string ";
  char t[1000] = "concat";
  void _strcat(char *, char *);
  _strcat(s, t);
  printf("%s\n", s);
  return 0;
}

