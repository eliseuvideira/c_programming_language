#include <stdio.h>

#define MAX_LINE 1000

int get_line(char line[], int max_length);
void reverse_line(char to[], char from[], int length);

int main() {
  int length;
  char current_line[MAX_LINE];
  char reversed_line[MAX_LINE];

  while ((length = get_line(current_line, MAX_LINE)) > 0) {
    reverse_line(reversed_line, current_line, length);
    printf("%s", reversed_line);
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

void reverse_line(char to[], char from[], int length) {
  int i;
  for (i = length - 1; i >= 0; --i) {
    to[i] = from[length - 1 - i];
  }
  to[length] = '\0';
}
