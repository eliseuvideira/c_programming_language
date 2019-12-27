#include <stdio.h>

#define MAX_LENGTH 65535

void read_text(char s[]);
void expand(char s1[], char s2[]);
int is_alphanumeric(char c);

int main() {
  char s[MAX_LENGTH], t[MAX_LENGTH];

  read_text(s);

  expand(s, t);

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

void expand(char s1[], char s2[]) {
  int i, j, c;

  s2[0] = s1[0];
  for (i = j = 1; s1[i] != '\0'; ++i) {
    if (s1[i] == '-' && (is_alphanumeric(s1[i - 1])) && (is_alphanumeric(s1[i + 1])) && s1[i - 1] + 1 < s1[i + 1]) {
      for (c = s1[i - 1] + 1; c < s1[i + 1]; ++c, ++j) {
        s2[j] = c;
      }
    } else {
      s2[j] = s1[i];
      ++j;
    }
  }
  s2[++j] = '\0';
}

int is_alphanumeric(char c) {
  if (c >= 'a' && c <= 'z') {
    return 1;
  }
  if (c >= 'A' && c <= 'A') {
    return 1;
  }
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}


