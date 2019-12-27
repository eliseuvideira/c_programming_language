#include <stdio.h>

#define MAX_LENGTH 65535

void read_text(char s[]);
void parse(char s[], char t[]);

int main() {
  char s[MAX_LENGTH], t[MAX_LENGTH];

  read_text(s);

  parse(s, t);

  printf("%s", t);

  return 0;
}

void read_text(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && i < MAX_LENGTH - 1; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
}

void parse(char s[], char t[]) {
  int i, j;
  for (i = j = 0; s[i] != EOF && i < MAX_LENGTH; ++i, ++j) {
    switch (s[i]) {
      case '\\':
        ++i;
        switch (s[i]) {
          case 'n':
            t[j] = '\n';
            break;
          case 't':
            t[j] = '\t';
            break;
          default:
            t[j] = '\\';
            t[++j] = s[i];
            break;
        }
        break;
      default:
        t[j] = s[i];
        break;
    }
  }
  t[j] = '\0';
}

