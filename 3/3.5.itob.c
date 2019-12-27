#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 65535

void itob(int n, char s[], int b);
void reverse(char s[]);
int power(int base, int exponent);
int abs(int n);

int main() {
  int n = MAX_LENGTH;
  char s[MAX_LENGTH];

  itob(n, s, 16);

  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int b) {
  int i, value, c;

  value = n;
  i = 0;
  do {
    c = abs(value % b);
    s[i++] = c > 9 ? c + 'a' - 10 : c + '0';
  } while ((value /= b) != 0);
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

