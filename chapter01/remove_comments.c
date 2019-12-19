// this line should not appear in the output;
/* 
  this 
  lines 
  also 
*/
#include <stdio.h>

#define IN  1
#define OUT 0

void remove_comments(int c) ;
void remove_multi_line_comment();
void remove_single_line_comment();
void print_quote(int c);
void print_char(int c);

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    remove_comments(c);
  }
  putchar('"');
  printf("This /* will not */ be removed, also not // this \"\n");
}

void remove_comments(int c) {
  int d;
  if (c == '"') {
    print_quote(c);
  } else if (c == '\'') {
    print_char(c);
  } else if (c == '/') {
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

void print_quote(int c) {
  int scaped = OUT;
  putchar(c);
  do {
    if (c == '\\') {
      if (scaped == OUT) {
        scaped = IN;
      } else {
        scaped = OUT;
      }
    } else {
      scaped = OUT;
    }
    putchar((c = getchar()));
  } while (c != '"' || scaped == IN);
}

void print_char(int c) {  
  int scaped = OUT;
  putchar(c);
  do {
    if (c == '\\') {
      if (scaped == OUT) {
        scaped = IN;
      } else {
        scaped = OUT;
      }
    } else {
      scaped = OUT;
    }
    c = getchar();
    putchar(c);
  } while (c != '\'' || scaped == IN);
}
