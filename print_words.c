#include <stdio.h>

#define IN  0
#define OUT 1

int main() {
  int c;
  int state = OUT;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    } else {
      if (state == OUT) {
        state = IN;
      }
      putchar(c);
    }
  }
  putchar('\n');
  
  return 0;
}