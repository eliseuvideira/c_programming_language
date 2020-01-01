#include <string.h>
#include "key.h"

struct key *bin_search(char *word, struct key tab[], int n) {
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n];
  struct key *mid;
  int strcomp(char *, char *);
  while (low < high) {
    mid = low + (high - low) / 2;
    if ((cond = strcomp(word, mid->word)) < 0) {
      high = mid;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return NULL;
}

