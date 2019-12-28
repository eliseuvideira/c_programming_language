#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 65535

double atof(char s[]);
int get_line(char s[], int max);
double power(double base, int exp);

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
  int exp;
  int i, sign, exp_sign;

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
  exp_sign = 1;
  exp = 0;
  if (s[i] == 'e' || s[i] == 'E') {
    ++i;
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
      ++i;
    }
    for (exp = 0; isdigit(s[i]); ++i) {
      exp = exp * 10 + (s[i] - '0');
    }
  }

  return (sign * x / p) * power(10, exp_sign * exp);
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

double power(double base, int exp) {
  int i;
  double value = 1.0;
  if (exp < 0) {
    for (i = exp; i < 0; ++i) {
      value = value / base;
    }
  } else {
    for (i = 0; i < exp; ++i) {
      value = value * base;
    }
  }

  return value;
}

