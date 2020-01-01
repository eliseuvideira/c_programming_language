#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "key.h"

#define MAX_WORD 100

extern struct key keytab[32];
int get_word(char *, int);
struct key *bin_search(char *, struct key *, int);

int main() {
  char word[MAX_WORD];
  struct key *p;
  while (get_word(word, MAX_WORD) != EOF) {
    if (isalpha(word[0])) {
      if ((p = bin_search(word, keytab, NKEYS)) != NULL) {
        p->count++;
      }
    }
  }
  for (p = keytab; p < keytab + NKEYS; ++p) {
    if (p->count > 0) {
      printf("%4d %s\n", p->count, p->word);
    }
  }
  return 0;
}

