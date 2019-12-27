#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 65535

void itoa(int n, char s[]);
void reverse(char s[]);
int power(int base, int exponent);
int abs(int n);

int main() {
  int n = INT_MIN + 1;
  char s[MAX_LENGTH];

  itoa(n, s);

  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[]) {
  int i, value;

  value = n;
  i = 0;
  do {
    s[i++] = abs(value % 10) + '0';
  } while ((value /= 10) != 0);
  if (n < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i], s[i] = s[j], s[j] = c;
  }
}

int power(int base, int exponent) {
  int value;
  for (value = 1; exponent > 0; --exponent) {
    value = value * base;
  }
  return value;
}

int abs(int n) {
  return n < 0 ? -n : n;
}

