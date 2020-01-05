#include <stdio.h>
#include <stdlib.h>

void push(double);
double pop();

void sum(void) {
  double x, y;
  y = pop();
  x = pop();
  push(x + y);
}

void subtract(void) {
  double x, y;
  y = pop();
  x = pop();
  push (x - y);
}

void multiply(void) {
  double x, y;
  y = pop();
  x = pop();
  push(x * y);
}

void divide(void) {
  double x, y;
  y = pop();
  x = pop();
  if (y == 0) {
    printf("error: division by zero\n");
    exit(1);
  }
  push(x / y);
}

char is_operator(char *s) {
  if (*(s + 1) != '\0') {
    printf("error: unprocessable operator\n");
    exit(1);
  }
  return *s;
}

int is_number(char *s) {
  if (*s == '+' || *s == '-') {
    s++;
  }
  if (*s == '\0') {
    return 0;
  }
  while (*s >= '0' && *s <= '9') {
    s++;
  }
  if (*s == '.') {
    s++;
  }
  while (*s >= '0' && *s <= '9') {
    s++;
  }
  if (*s != '\0') {
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  char operator;
  void sum(void);
  void subtract(void);
  void multiply(void);
  void divide(void);
  argc--;
  argv++;
  while (argc > 0) {
    if (is_number(*argv)) {
      push(atof(*argv));
    } else if (operator = is_operator(*argv)) {
      switch (operator) {
        case '+':
          sum();
          break;
        case '-':
          subtract();
          break;
        case '*':
          multiply();
          break;
        case '/':
          divide();
          break;
        default:
          printf("error: unknown operator\n");
          exit(1);
          break;
      }
    } else {
      printf("error: unknown argument `%s`\n", *argv);
      exit(1);
    }
    argc--;
    argv++;
  }
  printf("%f\n", pop());
  return 0;
}

