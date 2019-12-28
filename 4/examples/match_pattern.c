#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int max);
int str_index(char s[], char p[]);

char pattern[] = "ould";

int main() {
  char line[MAXLINE];
  int found = 0;

  while (get_line(line, MAXLINE) > 0) {
    if (str_index(line, pattern) >= 0) {
      printf("%s", line);
      ++found;
    }
  }

  return found;
}

int get_line(char s[], int max) {
  int c, i;

  i = 0;
  while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int str_index(char s[], char p[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; p[k] != '\0' && s[j] == p[k]; ++j, ++k);
    if (k > 0 && p[k] == '\0') {
      return i;
    }
  }

  return -1;
}

