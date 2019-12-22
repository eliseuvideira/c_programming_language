#include <stdio.h>

#define MAX_LENGTH 1000

int any(char s1[], char s2[]);
void get_line(char s[], int max_length);

int main() {
  int pos;
  char s1[MAX_LENGTH];
  char s2[MAX_LENGTH];

  get_line(s1, MAX_LENGTH);
  get_line(s2, MAX_LENGTH);

  pos = any(s1, s2);

  printf("%d\n", pos);

  return 0;
}

void get_line(char s[], int max_length) {
  int i;
  for (i = 0; (s[i] = getchar()) != '\n' && i < max_length; ++i);
  s[i] = '\0';
}

int any(char s1[], char s2[]) {
  int pos = -1;
  int i, j;
  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; ; ++j) {
      if (s2[j] == '\0') {
        pos = i;
        break;
      } else {
        if (s1[i + j] != s2[j]) {
          break;
        }
      }
    }
    if (pos != -1) {
      break;
    }
  }
}
