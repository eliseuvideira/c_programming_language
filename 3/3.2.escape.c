#include <stdio.h>

#define MAX_LENGTH 65535

void read_text(char s[]);
void escape_text(char s[], char t[]);

int main() {
  char s[MAX_LENGTH], t[MAX_LENGTH];

  read_text(s);

  escape_text(s, t);

  printf("%s\n", t);

  return 0;
}

void read_text(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && i < MAX_LENGTH - 1; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
}

void escape_text(char s[], char t[]) {
  int i, j;
  for (i = j = 0; s[i] != EOF && i < MAX_LENGTH - 1; ++i) {
    switch (s[i]) {
      case '\n':
        t[j] = '\\';
        t[++j] = 'n';
        break;
      case '\t':
        t[j] = '\\';
        t[++j] = 't';
        break;
      default:
        t[j] = s[i];
        break;
    }
    ++j;
  }
  t[j] = '\0';
}

