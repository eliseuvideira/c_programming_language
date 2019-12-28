#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 65535

double atof(char s[]);
int get_line(char s[], int max);

int main() {
  char s[MAX_LENGTH];
  double value;

  get_line(s, MAX_LENGTH);

  value = atof(s);

  printf("%10.6f\n", value);

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

