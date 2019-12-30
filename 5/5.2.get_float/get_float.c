#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int get_float(double *pn) {
  int c, sign;
  double exp = 1;

  while (isspace(c = getch()));

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (double)(c - '0');
  }
  if (c == '.') {
    while (isdigit(c = getch())) {
      exp = exp * 10.0;
      *pn = 10.0 * *pn + (double)(c - '0');
    }
  }
  *pn *= sign / exp;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}

