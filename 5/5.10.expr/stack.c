#include <stdio.h>
#define MAXVAL 100

void push(double);
double pop();

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

