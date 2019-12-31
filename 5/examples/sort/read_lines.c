#include <stddef.h>
#define MAX_LENGTH 1000

int read_lines(char *lines[], int max_lines) {
  int len, lines_read;
  char *p, line[MAX_LENGTH];
  int get_line(char *, int);
  char *alloc(int);
  void str_copy(char *, char *);
  lines_read = 0;
  while ((len = get_line(line, MAX_LENGTH)) > 0) {
    if (lines_read >= max_lines || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0'; // remove new line character
      str_copy(line, p);
      lines[lines_read++] = p;
    }
  }
  return lines_read;
}

