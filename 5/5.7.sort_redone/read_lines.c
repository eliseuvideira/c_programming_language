#include <stddef.h>
#define MAX_LENGTH 1000
#define MAX_STORE 5000

int read_lines(char *lines[], char *line_store, int max_lines) {
  int len, lines_read;
  char *p, line[MAX_LENGTH];
  p = line_store;
  char *line_stop = line_store + MAX_STORE;
  int get_line(char *, int);
  void str_copy(char *, char *);
  lines_read = 0;
  while ((len = get_line(line, MAX_LENGTH)) > 0) {
    if (lines_read >= max_lines || p + lines_read > line_stop) {
      return -1;
    } else {
      line[len - 1] = '\0'; // remove new line character
      str_copy(line, p);
      lines[lines_read++] = p;
      p += len;
    }
  }
  return lines_read;
}

