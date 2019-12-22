#include <stdio.h>

void print_char();
void print_string();
void print_single_line_comment();
void print_multi_line_comment();

int main() {
  int c;
  int paren = 0, brackets = 0, braces = 0;

  while ((c = getchar()) != EOF) {
    // putchar(c);
    if (c == '"') {
      print_string();
    } else if (c == '\'') {
      print_char();
    } else if (c == '/') {
      c = getchar();
      if (c == EOF) {
        break;
      } else if (c == '*') {
        print_multi_line_comment();
      } else if (c == '/') {
        print_single_line_comment();
      }
    } else if (c == '{') {
      ++braces;
    } else if (c == '}') {
      --braces;
    } else if (c == '(') {
      ++paren;
    } else if (c == ')') {
      --paren;
    } else if (c == '[') {
      ++brackets;
    } else if (c == ']') {
      --brackets;
    }
  }

  if (braces != 0 || paren != 0 || brackets != 0) {
    printf("There are errors in the script");
    return 1;
  }

  return 0;
}

void print_char() {
  int c;

  while ((c = getchar()) != EOF) {
    // putchar(c);
    if (c == '\\') {
      getchar();
    } else if (c == '\'') {
      break;
    }
  }
};

void print_string() {
  int c;

  while ((c = getchar()) != EOF) {
    // putchar(c);
    if (c == '\\') {
      getchar();
    } else if (c == '"') {
      break;
    }
  }
};

void print_single_line_comment() {
  int c;

  while ((c = getchar()) != EOF && c != '\n') {
    // putchar(c);
  }
};

void print_multi_line_comment() {
  int c, d;

  while ((c = getchar()) != EOF) {
    if (d == '*' && c == '/') {
      break;
    }
    d = c;
  }
};
