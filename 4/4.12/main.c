#include <stdio.h>
#define MAXLINE 1000

int main() {
  int i = -1254;
  char s[MAXLINE];
  void itoa(int, char[]);

  itoa(i, s);
  printf("%s", s);
}

