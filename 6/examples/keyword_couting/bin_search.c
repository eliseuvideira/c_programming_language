#include "key.h"

int bin_search(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;
  int strcomp(char *, char *);
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcomp(word, tab[mid].word)) < 0) {
      high = mid - 1;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

