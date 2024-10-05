#pragma once

#include <stddef.h>

typedef struct Node
{
  void *data;
  struct Node *next;
} Node;

Node *createLinkedList(size_t total_elements, size_t data_size);
void freeLinkedList(Node *HEAD);
void displayLinkedList(Node *head, void (*display)(void *), char *seperator);