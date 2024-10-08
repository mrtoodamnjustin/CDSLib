#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// typedef struct Node
// {
//   void *data;
//   Node *next;
// } Node;

Node *ll_create(size_t total_elements, size_t element_size)
{
  Node *HEAD = malloc(sizeof(Node));

  HEAD->data = malloc(element_size);

  Node *curretNode = HEAD;
  for (size_t i = 1; i < total_elements; i++)
  {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(element_size);
    curretNode->next = newNode;
    curretNode = newNode;
  }
  curretNode->next = NULL;

  return HEAD;
}

void ll_free(Node *HEAD)
{
  Node *currentNode = HEAD;
  Node *nextNode;

  while (currentNode != NULL)
  {
    nextNode = currentNode->next;
    free(currentNode->data);
    free(currentNode);
    currentNode = nextNode;
  }
}

void ll_display(Node *HEAD, void (*display)(void *), char *seperator)
{
  Node *currentNode = HEAD;

  while (currentNode != NULL)
  {
    display(currentNode->data);

    if (currentNode->next != NULL)
      printf("%s", seperator);

    currentNode = currentNode->next;
  }
}