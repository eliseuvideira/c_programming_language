#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tree_node.h"

#define MAX_WORD 100

int main() {
  void tree_print(struct tree_node *);
  struct tree_node *add_tree(struct tree_node *, char *);
  int get_word(char *, int);
  struct tree_node *root;
  char word[MAX_WORD];
  root = NULL;
  while (get_word(word, MAX_WORD) != EOF) {
    if (isalpha(word[0])) {
      root = add_tree(root, word);
    }
  }
  tree_print(root);
  return 0;
}

