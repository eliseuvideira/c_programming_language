#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int main() {
  double sum, atof(char s[]);
  char line[MAXLINE];
  int get_line(char line[], int max);

  sum = 0;
  while (get_line(line, MAXLINE) > 0) {
    printf("\t%g\n", sum += atof(line));
  }

  return 0;
}

double atof(char s[]) {
  double x, p;
  int i, sign;

  for (i = 0; isspace(s[i]); ++i);

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-') {
    ++i;
  }

  for (x = 0.0; isdigit(s[i]); ++i) {
    x = 10.0 * x + (s[i] - '0');
  }
  if (s[i] == '.') {
    ++i;
  }
  for (p = 1; isdigit(s[i]); ++i) {
    x = 10.0 * x + (s[i] - '0');
    p *= 10.0;
  }

  return sign * x / p;
}

int get_line(char s[], int max) {
  int c, i;

  i = 0;
  while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

