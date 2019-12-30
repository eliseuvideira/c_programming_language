#include <stdio.h>

int get_line(char *s, int max_length) {
  int c;
  int length = 0;
  while ((c = getchar()) != EOF && c != '\n' && length < max_length) {
    *s = c;
    s++;
    length++;
  }
  if (c == '\n') {
    *s = c;
    s++;
  }
  *s = '\0';
  return length;
}

