#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> // to compile, run cc <filename> -lm

#define MAXOP 100
#define NUMBER '0'

int get_operator(char []);
void push(double);
double pop();
void print_top();
void swap();
void clear();
void duplicate();
double variables[26];
double last_value;

int main() {
  int type;

  double x, y;

  char s[MAXOP];
  char last_variable;

  while ((type = get_operator(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        x = pop();
        y = pop();
        push(x + y);
        break;
      case '*':
        x = pop();
        y = pop();
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
      case 'p': // print
        print_top();
        break;
      case 'd': // duplicate
        duplicate();
        break;
      case 's': // swap
        swap();
        break;
      case 'c': // clear
        clear();
        break;
      case '^': // power
        y = pop();
        x = pop();
        push(pow(x, y));
        break;
      case 'e': // exp
        x = pop();
        push(exp(x));
        break;
      case '|': // sin
        x = pop();
        push(sin(x));
        break;
      case '=':
        pop();
        if (last_variable >= 'A' && last_variable <= 'Z') {
          variables[last_variable - 'A'] = pop();
        } else {
          printf("error: no variable to assign to\n");
        }
        break;
      case 'v':
        push(last_value);
        break;
      case '\n':
        x = pop();
        printf("\t%.8g\n", x);
        last_value = x;
        break;
      default:
        if (type >= 'A' && type <= 'Z') {
          push(variables[type - 'A']);
          last_variable = type;
        } else {
          printf("error: unknown command %s\n", s);
        }
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

void print_top() {
  double top = pop();
  printf("\t%10.8f\n", top);
  push(top);
}

void duplicate() {
  double x = pop();
  push(x);
  push(x);
}

void swap() {
  double x, y;
  x = pop();
  y = pop();
  push(x);
  push(y);
}

void clear() {
  while (sp > 0) {
    pop();
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

