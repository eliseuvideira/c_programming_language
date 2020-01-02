#include <stdio.h>
#include <string.h>
#include "tree_node.h"

void tree_print(struct tree_node *p) {
  if (p != NULL) {
    tree_print(p->left);
    printf("%4d %s\n", p->count, p->word);
    tree_print(p->right);
  }
}
