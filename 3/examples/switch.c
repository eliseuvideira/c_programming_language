#include <stdio.h>

int main() {
  int c, i, blanks, other, digits[10];

  blanks = other = 0;
  for (i = 0; i < 10; ++i) {
    digits[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        ++digits[c - '0'];
        break;
      case ' ': case '\n': case '\t':
        ++blanks;
        break;
      default:
        ++other;
        break;
    }
  }
  printf("digits =");
  for (i = 0; i < 10; ++i) {
    printf(" %d", digits[i]);
  }
  printf(", white space = %d, other = %d\n", blanks, other);

  return 0;
}
