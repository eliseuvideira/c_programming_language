#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define NAMED '1'

int get_operator(char s[]);

int main() {
  int type;

  double x, y;

  char s[MAXOP];

  void push(double);
  double pop(void);

  while ((type = get_operator(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case NAMED:
        if (strcmp(s, "print") == 0) {
          x = pop();
          printf("\t%10.8f\n", x);
          push(x);
        } else if (strcmp(s, "duplicate") == 0) {
          x = pop();
          push(x);
          push(x);
        } else if (strcmp(s, "swap") == 0) {
          y = pop();
          x = pop();
          push(y);
          push(x);
        }
        break;
      case '+':
        y = pop();
        x = pop();
        push(x + y);
        break;
      case '*':
        y = pop();
        x = pop();
        push(x * y);
        break;
      case '-':
        y = pop();
        x = pop();
        push(x - y);
        break;
      case '/':
        y = pop();
        x = pop();
        if (y != 0.0) {
          push(x / y);
        } else {
          printf("error: division by zero\n");
        }
        break;
      case '%':
        y = pop();
        x = pop();
        if ((int)y != 0) {
          push((int)x % (int)y);
        } else {
          printf("error: division by zero\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  return 0;
}

int get_operator(char s[]) {
  int i, c;

  char getch(void);
  void ungetch(char);

  while ((s[0] = c = getch()) == ' ' || c == '\t');

  s[1] = '\0';
  i = 0;
  if (!isdigit(c) && c != '.' && c != '-' && !islower(c)) {
    return c;
  }

  if (islower(c)) {
    while (islower(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF) {
      ungetch(c);
    }
    if (strlen(s) > 1) {
      return NAMED;
    } else {
      return c;
    }
  }
  if (c == '-') {
    if (isdigit(c = getch()) || c == '.') {
      s[++i] = c;
    } else {
      if (c != EOF) {
        ungetch(c);
      }
      return '-';
    }
  }
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()));
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()));
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}

