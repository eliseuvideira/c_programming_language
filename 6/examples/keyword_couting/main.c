#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "key.h"

#define MAX_WORD 100

extern struct key keytab[32];
int get_word(char *, int);
int bin_search(char *, struct key *, int);

int main() {
  int n;
  char word[MAX_WORD];
  while (get_word(word, MAX_WORD) != EOF) {
    if (isalpha(word[0])) {
      if ((n = bin_search(word, keytab, NKEYS)) >= 0) {
        keytab[n].count++;
      }
    }
  }
  for (n = 0; n < NKEYS; ++n) {
    if (keytab[n].count > 0) {
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }
  }
  return 0;
}


