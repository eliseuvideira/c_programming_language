#include <stdlib.h>
#include <string.h>

char *duplicate_string(char *s) {
  char *p;
  p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
  if (p != NULL) {
    strcpy(p, s);
  }
  return p;
}

