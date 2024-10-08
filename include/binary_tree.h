#pragma once

#include <stddef.h>

typedef struct btNode
{
  void *data;
  struct btNode *left;
  struct btNode *right;
} btNode;

btNode *bt_create_node(const void *data, size_t element_size);