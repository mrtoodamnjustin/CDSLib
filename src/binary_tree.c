#include "binary_tree.h"

#include <string.h>

btNode *createNode(const void *data, size_t element_size)
{
  btNode *node = malloc(sizeof(btNode));

  node->data = malloc(sizeof(element_size));

  memcpy(data, node->data, element_size);
}