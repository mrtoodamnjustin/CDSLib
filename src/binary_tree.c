#include "binary_tree.h"

#include <stdlib.h>
#include <string.h>

btNode *bt_create_node(const void *data, size_t element_size)
{
  btNode *node = malloc(sizeof(btNode));

  node->data = malloc(sizeof(element_size));

  memcpy(node->data, data, element_size);

  node->left = NULL;
  node->right = NULL;

  return node;
}