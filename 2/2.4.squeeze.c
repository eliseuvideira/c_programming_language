#include <stdio.h>

#define TRUE  1
#define FALSE 0

void squeeze(char s1[], char s2[]);
int contains(char s[], char c);

int main() {
  int i;
  char s1[1000];
  char s2[3];

  for (i = 0; (s1[i] = getchar()) != EOF; ++i);
  s1[i] = '\0';

  s2[0] = 'a';
  s2[1] = 'b';
  s2[2] = '\0';

  squeeze(s1, s2);

  printf("%s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; ++i) {
    if (contains(s2, s1[i]) == FALSE) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';  
}

int contains(char s[], char c) {
  int i;
  int r = FALSE;
  for (i = 0; s[i] != '\0'; ++i) {
    if (c == s[i]) {
      r = TRUE;
      break;
    }
  }
  return r;
}
