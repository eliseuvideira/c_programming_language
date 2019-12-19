#include <stdio.h>

#define MAXWIDTH   1000
#define LINELENGTH 80

int get_line(char line[], int max_length);

int main() {
  int length;
  char current_line[MAXWIDTH];

  while ((length = get_line(current_line, MAXWIDTH)) > 0) {
    if (length > LINELENGTH) {
      printf("%s", current_line);
    }
  }

  return 0;
}

int get_line(char line[], int max_length) {
  int c, i;

  for (i = 0; i < max_length - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}
