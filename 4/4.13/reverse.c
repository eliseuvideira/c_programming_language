#include <string.h>

void reverse(char s[]) {
  int len;
  void reverse_recurse(char[], int, int);
  len = strlen(s);
  reverse_recurse(s, 0, len);
}

void reverse_recurse(char s[], int pos, int len) {
  char temp;
  int reverse_pos;
  reverse_pos = len - pos - 1;
  if (pos < reverse_pos) {
    temp = s[pos];
    s[pos] = s[reverse_pos];
    s[reverse_pos] = temp;
    reverse_recurse(s, pos + 1, len);
  }
}

