#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int get_word(char *word, int lim) {
  int c, d;
  char *w = word;
  int single_line_comment(void);
  int multi_line_comment(void);
  while (isspace(c = getch()));
  if (c != EOF) {
    *w = c;
    w++;
  }
  if (isalpha(c) || c == '_' || c == '#') {
    // c is letter or underscore or preprocessor
    for (; --lim > 0; w++) {
      if (!isalnum(*w = getch()) && *w != '_') {
        ungetch(*w);
        break;
      }
    }
  } else if (c == '"' || c == '\'') {
    // c is a string or char
    for (; --lim > 0; w++) {
      if ((*w = getch()) == '\\') {
        *++w = getch();
      } else if (*w == c) {
        w++;
        break;
      } else if (*w == EOF) {
        break;
      }
    }
  } else if (c == '/') {
    if ((d = getch()) == '*') {
      c = multi_line_comment();
    } else if (d == '/') {
      c = single_line_comment();
    } else {
      ungetch(d);
    }
  }
  *w = '\0';
  return c;
}

int multi_line_comment(void) {
  int c;
  while ((c = getch()) != EOF) {
    if (c == '*') {
      if ((c = getch()) == '/') {
        break;
      } else {
        ungetch(c);
      }
    }
  }
  return c;
}

int single_line_comment(void) {
  int c;
  while ((c = getch()) != EOF) {
    if (c == '\n') {
      break;
    }
  }
  return c;
}

