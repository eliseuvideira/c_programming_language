#include <stdio.h>

void write_lines(char *lines[], int line_count) {
  int i;
  for (i = 0; i < line_count; ++i) {
    printf("%s\n", lines[i]);
  }
}

