#pragma once

#include <stddef.h>

typedef struct btNode
{
  void *data;
  struct btNode *left;
  struct btNode *right;
} btNode;

btNode *createNode(const void *data, size_t element_size);