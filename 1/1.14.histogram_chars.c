#include <stdio.h>

#define MAXHIST 15
#define MAXCHAR 128

int main() {
  int char_count[MAXCHAR];
  int i, c;

  for (i = 0; i < MAXCHAR; i++) {
    char_count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++char_count[c];
  }

  int max = 0;
  for (i = 0; i < MAXCHAR; i++) {
    if (char_count[i] > max) {
      max = char_count[i];
    }
  }

  int j;

  for (i = 0; i < MAXCHAR; i++) {
    if (char_count[i] > 0) {
      printf("%c: ", i);
      for (j = 0; j < MAXHIST * char_count[i] / max; ++j) {
        putchar('*');
      }
      putchar('\n');
    }
  }

  return 0;
}
