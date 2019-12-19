#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int limit);
void copy_line(char to[], char from[]);

int main() {
  int length;
  int max_length;
  char current_line[MAXLINE];
  char longest_line[MAXLINE];

  max_length = 0;
  while ((length = get_line(current_line, MAXLINE)) > 0) {
    if (length > max_length) {
      max_length = length;
      copy_line(longest_line, current_line);
    }
  }

  if (max_length > 0) {
    printf("%s", longest_line);
  }

  return 0;
}

int get_line(char line[], int limit) {
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy_line(char to[], char from[]) {
  int i = 0;
  for (i = 0; (to[i] = from[i]) != '\0'; ++i);
}
