#include <stdio.h>
#define MAX_LINES 5000

char *lines[MAX_LINES];
char line_store[5000];
int read_lines(char *[], char *, int);
void quick_sort(char *[], int, int);
void write_lines(char *[], int);

int main() {
  int lines_read;
  if ((lines_read = read_lines(lines, line_store, MAX_LINES)) >= 0) {
    quick_sort(lines, 0, lines_read - 1);
    write_lines(lines, lines_read);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

