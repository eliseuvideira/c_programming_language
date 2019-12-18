#include <stdio.h>

#define MAX_TEXT_WIDTH 150000
#define MAX_LINE_WIDTH 1000

int get_line(char line[], int max_length);
int remove_trailing(char line[], int length);
int append_text(char text[], int position, int max_length, char line[]);

int main() {
  char text[MAX_TEXT_WIDTH];
  char current_line[MAX_LINE_WIDTH];
  int length;
  int text_length = 0;

  while ((length = get_line(current_line, MAX_LINE_WIDTH)) > 0) {
    if (length > 1) {
      length = remove_trailing(current_line, length);
      if (length > 1) {
        text_length = append_text(text, text_length, MAX_TEXT_WIDTH, current_line);
      }
    }
  }

  printf("%s", text);

  return 0;
}

int get_line(char line[], int max_length) {
  int c, i;

  for (i = 0; i < max_length - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}

int remove_trailing(char line[], int length) {
  int i;
  for (i = length - 1; i > 0 && (line[i] == ' ' || line[i] == '\t') ; --i) {
    line[i] = '\n';
    line[i + 1] = '\0';
  }
  return i;
}

int append_text(char text[], int position, int max_length, char line[]) {
  int i;
  for (i = 0; i < max_length - 1 && line[i] != '\0'; ++i) {
    text[position + i] = line[i];
  }
  text[position + i + 1] = '\0';
  return position + i;
}
