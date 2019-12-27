#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverse(char s[]);

int main() {
  char c;
  char text[MAX_LENGTH];
  int i = 0;

  while ((c = getchar()) != EOF && i < MAX_LENGTH) {
    text[i] = c;
    ++i;
  }
  text[i] = '\0';

  printf("%s\n", text);

  reverse(text);

  printf("%s\n", text);

  return 0;
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

