#include "binary_tree.h"

#include <stdlib.h>
#include <string.h>

btNode *createNode(const void *data, size_t element_size)
{
  btNode *node = malloc(sizeof(btNode));

  node->data = malloc(sizeof(element_size));

  memcpy(node->data, data, element_size);

  return node;
}