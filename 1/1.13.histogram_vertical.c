#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0

int main() {
  int c, i, j, word_length, overflow_count, max_length;
  int word_length_count[MAXWORD];
  int state = OUT;

  word_length = 0;
  overflow_count = 0;
  
  for (i = 0; i < MAXWORD; i++) {
    word_length_count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        if (word_length >= MAXWORD) {
          overflow_count++;
        } else {
          word_length_count[word_length]++;
        }
      }
      word_length = 0;
    } else {
      if (state == OUT) {
        state = IN;
      }
      word_length++;
    }
  }

  max_length = 0;
  for (i = 1; i < MAXWORD; i++) {
    if (max_length < word_length_count[i]) {
      max_length = word_length_count[i];
    }
  }

  for (i = 1; i < MAXWORD; i++) {
    printf("|%4d  ", i);
  }
  printf("|  11+ ");
  printf("|\n");

  for (i = 0; i < MAXHIST; i++) {
    for (j = 1; j < MAXWORD; j++) {
      if (word_length_count[j] * MAXHIST / max_length > i) {
        printf("|  **  ");
      } else {
        printf("|      ");
      }
    }
    if (overflow_count * MAXHIST / max_length > i) {
      printf("|  **  ");
    } else {
      printf("|      ");
    }
    printf("|\n");
  }

  for (i = 1; i < MAXWORD; i++) {
    printf("|%6d", word_length_count[i]);
  }
  printf("|%6d", overflow_count);
  printf("|\n");

  return 0;
}
