#include <ctype.h>

int str_to_int(char *s) {
  int x = 0;
  // ignore space
  for (; isspace(*s); ++s);
  while (*s >= '0' && *s <= '9') {
    x = x * 10 + (*s - '0');
    ++s;
  }
  return x;
}

