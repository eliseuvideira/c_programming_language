#include <math.h>
#include <stdio.h>

int abs(int);

void itoa(int n, char s[]) {
  static int index;
  printf("%d\n", index);

  if (n / 10) {
    itoa(n / 10, s);
  } else {
    index = 0;
    if (n < 0) {
      s[index++] = '-';
    }
  }
  s[index++] = abs(n) % 10 + '0';
  s[index] = '\0';
}

