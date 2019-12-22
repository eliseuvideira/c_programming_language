#include <stdio.h>

int htoi(char hex[]);
int power(int base, int exp);

int main() {
  int c;
  int pos = 0;
  char hex[10];
  int value;

  while ((c = getchar()) != EOF && c != '\n') {
    hex[pos] = c;
    ++pos;
  }
  hex[pos] = '\0';

  value = htoi(hex);

  printf("%s -> %d\n", hex, value);

  return 0;
}

int htoi(char hex[]) {
  int pos = 0;
  int i;
  int length = 0;
  int result;
  if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
    pos += 2;
  }

  for (length = 0; hex[length] != '\0'; ++length);

  result = power(16, length - pos) - 1;

  return result;
}

int power(int base, int exp) {
  int i;
  int value = 1;
  for (i = 0; i < exp; ++i) {
    value = value * base;
  }
  return value;
}
