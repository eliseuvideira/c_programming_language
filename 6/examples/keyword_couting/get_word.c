#include <stdio.h>
#include <ctype.h>

int get_word(char *word, int lim) {
  int c;
  int getch(void);
  void ungetch(int);
  char *w = word;
  while (isspace(c = getch()));
  if (c != EOF) {
    *w = c;
    w++;
  }
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++) {
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

