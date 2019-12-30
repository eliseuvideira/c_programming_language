#include <ctype.h>
#include <stdlib.h>

void int_to_str(int n, char *s) {
  void int_to_str_recurse(int, char *);
  void str_reverse(char *);
  int_to_str_recurse(n, s);
  str_reverse(s);
}

void int_to_str_recurse(int n, char *s) {
  *s = abs(n) % 10 + '0';
  ++s;
  if (n / 10 != 0) {
    int_to_str_recurse(n / 10, s);
  } else {
    if (n < 0) {
      *s = '-';
      ++s;
    }
    *s = '\0';
  }
}

