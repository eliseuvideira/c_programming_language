#include <stdio.h>

int htoi(char hex[]);
int power(int base, int exp);
int hex_to_int(char hex);

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
  int result = 0;
  if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
    pos += 2;
  }

  for (length = 0; hex[pos + length] != '\0'; ++length);

  for (i = 0; i < length; ++i) {
    result = result + hex_to_int(hex[pos + i]) * power(16, length - i - 1);
  }

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

int hex_to_int(char hex) {
  if (hex >= '0' && hex <= '9') {
    return hex - '0';
  }
  if (hex >= 'A' && hex <= 'F') {
    return hex - 'A' + 10;
  }
  if (hex >= 'a' && hex <= 'f') {
    return hex - 'a' + 10;
  }
}
