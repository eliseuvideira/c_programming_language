#include <stdlib.h>
#include "tree_node.h"

struct tree_node *talloc(void) {
  return (struct tree_node *)malloc(sizeof(struct tree_node));
}

