#include <stdio.h>
#define MAXLINE 1000

int main() {
  // get_line
  char line[MAXLINE];
  int get_line(char *, int);
  while (get_line(line, MAXLINE) != 0) {
    printf("%s", line);
  }
  // str_to_int
  int value;
  int str_to_int(char *);
  value = str_to_int("123");
  printf("%d\n", value);
  // int_to_str
  char s[100];
  void int_to_str(int, char *);
  int_to_str(-120, s);
  printf("%s\n", s);
  // reverse
  char r[100] = "esrever";
  void str_reverse(char *);
  str_reverse(r);
  printf("%s\n", r);
  // str_index_of
  int str_index_of(char *, char *);
  printf("%d\n", str_index_of("Hello World", "ello"));
  printf("%d\n", str_index_of("Hello", "ASDF"));
  return 0;
}

