#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int get_operator(char s[]);

int main() {
  int type;

  double operand1, operand2;

  char s[MAXOP];

  void push(double);
  double pop(void);

  while ((type = get_operator(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        operand2 = pop();
        operand1 = pop();
        push(operand1 + operand2);
        break;
      case '*':
        operand2 = pop();
        operand1 = pop();
        push(operand1 * operand2);
        break;
      case '-':
        operand2 = pop();
        operand1 = pop();
        push(operand1 - operand2);
        break;
      case '/':
        operand2 = pop();
        operand1 = pop();
        if (operand2 != 0.0) {
          push(operand1 / operand2);
        } else {
          printf("error: division by zero\n");
        }
        break;
      case '%':
        operand2 = pop();
        operand1 = pop();
        if ((int)operand2 != 0) {
          push((int)operand1 % (int)operand2);
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
  if (!isdigit(c) && c != '.' && c != '-') {
    return c;
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

