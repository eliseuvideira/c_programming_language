#include <string.h>

void str_reverse(char *s) {
  int c;
  int i;
  int length = strlen(s);
  for (i = 0; i < length - i; i++) {
    c = *(s + i);
    *(s + i) = *(s + length - i - 1);
    *(s + length - i - 1) = c;
  }
}

