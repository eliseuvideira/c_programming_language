#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 65535

int strrindex(char s[], char t[]);
int get_line(char s[], int max);
int get_length(char s[]);

int main() {
  char s[MAX_LENGTH];
  char t[MAX_LENGTH];
  int pos;

  get_line(s, MAX_LENGTH);
  get_line(t, MAX_LENGTH);

  pos = strrindex(s, t);

  printf("%d\n", pos);

  return 0;
}

int strrindex(char s[], char t[]) {
  int i, j, k;

  int len = get_length(t);

  for (i = get_length(s) - 1; i >= 0; --i) {
    for (j = i, k = len - 1; k >= 0 && s[j] == t[k]; --j, --k);
    if (k < 0) {
      return i - (len - 1);
    }
  }

  return -1;
}

int get_line(char s[], int max) {
  int c, i;

  i = 0;
  while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int get_length(char s[]) {
  int i = 0;

  while (s[i] != '\0') {
    ++i;
  }

  return i;
}

