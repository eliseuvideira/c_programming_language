// this line should not appear in the output;
/* 
  this 
  lines 
  also 
*/
#include <stdio.h>

void remove_comments(int c) ;
void remove_multi_line_comment();
void remove_single_line_comment();

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    remove_comments(c);
  }
}

void remove_comments(int c) {
  int d;
  if (c == '/') {
    d = getchar();
    if (d == '*') {
      remove_multi_line_comment();
    } else if (d == '/') {
      remove_single_line_comment();
    } else {
      putchar(c);
      putchar(d);
    }    
  } else {
    putchar(c);
  }
}

void remove_multi_line_comment() {
  int c, d;
  c = getchar();
  d = getchar();
  while (c != '*' && d != '/') {
    c = d;
    d = getchar();
  }
}

void remove_single_line_comment() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
