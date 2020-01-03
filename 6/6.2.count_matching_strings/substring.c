#include <stdlib.h>
#include <string.h>

char *substring(char *s, int start_at, int end_at) {
  int len = strlen(s);
  if (start_at > end_at || start_at > len || start_at < 0) {
    return NULL;
  }
  char *t = (char *)malloc(end_at - start_at + 1);
  char *i = t;
  char *end = s + end_at;
  s = s + start_at;
  while (*i = *s) {
    if (*s == '\0' || s == end) {
      break;
    }
    ++i;
    ++s;
  }
  if (*i != '\0') {
    ++i;
    *i = '\0';
  }
  return t;
}

