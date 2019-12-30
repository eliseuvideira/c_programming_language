#include <stdio.h>

void strcpy_array(char *s, char *t);
void strcpy_pointer(char *s, char *t);

int main() {
  char s[1000] = "pointer";
  char t[1000] = "array";
  char u[1000] = "function";

  printf("%s\n%s\n", s, t);

  strcpy_array(s, t);

  printf("%s\n%s\n", s, t);

  strcpy_pointer(s, u);

  printf("%s\n%s\n", s, t);

  return 0;
}

void strcpy_array(char *s, char *t) {
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0') {
    ++i;
  }
}

void strcpy_pointer(char *s, char *t) {
  while ((*s = *t) != '\0') {
    ++s;
    ++t;
  }
}

