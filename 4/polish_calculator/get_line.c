#include <stdio.h>

int get_line(char line[], int limit);

int get_line(char line[], int max_length) {
  int c, i;

  for (i = 0; i < max_length - 1; ++i) {
    c = getchar();
    if (c == EOF) {
      break;
    } else if (c == '\n') {
      break;
    }
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}

