#include <stdio.h>

int strcmp_array(char *s, char *t);
int strcmp_pointer(char *s, char *t);

int main() {
  printf("%d, %d", strcmp_array("Hello World", "Hello"), strcmp_pointer("Hello World", "Hello"));

  return 0;
}

int strcmp_array(char *s, char *t) {
  int i;
  for (i = 0; s[i] == t[i]; ++i) {
    if (s[i] == '\0') {
      return 0;
    }
  }
  return s[i] - t[i];
}

int strcmp_pointer(char *s, char *t) {
  for (; *s == *t; ++s, ++t) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

