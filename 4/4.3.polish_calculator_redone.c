#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int get_operator(char []);
void push(double);
double pop();

int main() {
  int type;

  double operand1, operand2;

  char s[MAXOP];

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

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

double pop() {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
  }
}

int getch();
void ungetch(int);

int get_operator(char s[]) {
  int i, c;

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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

