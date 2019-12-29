#include <string.h>

void ungets(char s[]);

void ungets(char s[]) {
  int len = strlen(s);
  void ungetch(char);

  while (len > 0) {
    ungetch(s[--len]);
  }
}

