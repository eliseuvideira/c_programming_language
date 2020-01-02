#include <string.h>
#include "tree_node.h"

struct tree_node *talloc(void);
char *duplicate_string(char *);

struct tree_node *add_tree(struct tree_node *p, char *w) {
  int cond;
  if (p == NULL) {
    p = talloc();
    p->word = duplicate_string(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = add_tree(p->left, w);
  } else {
    p->right = add_tree(p->right, w);
  }
  return p;
}

