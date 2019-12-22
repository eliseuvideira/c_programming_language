#include <stdio.h>

#define MAX 10
#define MAX_LINE 1000
#define TAB_SIZE 4

int get_line(char line[], int max_length);
int last_blank(char line[], int length, int start, int end);

int main() {
  int length;
  char line[MAX_LINE];
  int lower_limit, upper_limit;
  int i;

  while ((length = get_line(line, MAX_LINE)) > 0) {
    if (length < MAX) {
      printf("%s", line);
    } else {
      lower_limit = 0;
      while ((upper_limit = last_blank(line, length, lower_limit, lower_limit + MAX - 1)) > lower_limit) {
        for (i = lower_limit; i <= upper_limit; ++i) {
          putchar(line[i]);
        }
        putchar('\n');
        lower_limit = upper_limit + 1;
      }
    }
  }

  return 0;
}

int get_line(char line[], int max_length) {
  int c, i;

  for (i = 0; i < max_length - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == '\t') {
      line[i] = ' ';
      while ((i + 1) % TAB_SIZE != 0 && i < max_length - 1) {
        line[++i] = ' ';
      }
    } else {
      line[i] = c;
    }
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}

int last_blank(char line[], int length, int start, int end) {
  if (end > length) {
    end = length;
  }
  int i;
  for (i = end; i > start; --i) {
    if (line[i] == ' ') {
      return i;
    }
  }
  return end;
}
