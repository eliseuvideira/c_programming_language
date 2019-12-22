#include <stdio.h>

#define MAX_LENGTH 1000

int get_line(char line[], int max_length);

int main() {
  char line[MAX_LENGTH];
  int length;

  while ((length = get_line(line, MAX_LENGTH)) > 0) {
    printf("%s", line);
  }

  return 0;
}

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

