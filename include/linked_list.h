#pragma once

#include <stddef.h>

typedef struct Node
{
  void *data;
  struct Node *next;
} Node;

Node *ll_create(size_t total_elements, size_t data_size);
void ll_free(Node *HEAD);
void ll_display(Node *head, void (*display)(void *), char *seperator);