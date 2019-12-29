#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAMED '1'
#define MAXLINE 100

int get_operator(char s[]);
int get_line(char line[], int limit);

int main() {
  int type;

  double x, y;

  char s[MAXOP];
  double variables[26];
  double last_value;
  char last_variable;
  int i;

  for (i = 0; i < 26; ++i) {
    variables[i] = 0.0;
  }

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
        } else if (strcmp(s, "sin") == 0) {
          x = pop();
          push(sin(x));
        } else if (strcmp(s, "cos") == 0) {
          x = pop();
          push(cos(x));
        } else if (strcmp(s, "pow") == 0) {
          y = pop();
          x = pop();
          push(pow(x, y));
        } else if (strcmp(s, "exp") == 0) {
          x = pop();
          push(exp(x));
        } else {
          printf("error: unknow command\n");
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
      case '=':
        pop();
        if (last_variable >= 'A' && last_variable <= 'Z') {
          variables[last_variable - 'A'] = pop();
        } else {
          printf("error: no variable to assign to\n");
        }
        break;
      case '|':
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

char line[MAXLINE];
int line_index = 0;

int get_operator(char s[]) {
  int i, c;

  if (line[line_index] == '\0') {
    if (get_line(line, MAXLINE) == 0) {
      return EOF;
    } else {
      line_index = 0;
    }
  }

  while ((s[0] = c = line[line_index++]) == ' ' || c == '\t');

  s[1] = '\0';
  i = 0;
  if (!isdigit(c) && c != '.' && c != '-' && !islower(c)) {
    return c;
  }

  if (islower(c)) {
    while (islower(s[++i] = c = line[line_index++]));
    s[i] = '\0';
    if (c != EOF) {
      line_index--;
    }
    if (strlen(s) > 1) {
      return NAMED;
    } else {
      return c;
    }
  }
  if (c == '-') {
    if (isdigit(c = line[line_index++]) || c == '.') {
      s[++i] = c;
    } else {
      if (c != EOF) {
        line_index--;
      }
      return '-';
    }
  }
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = line[line_index++]));
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = line[line_index++]));
  }
  s[i] = '\0';
  if (c != EOF) {
    line_index--;
  }
  return NUMBER;
}

