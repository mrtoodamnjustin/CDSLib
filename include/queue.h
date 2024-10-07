#pragma once

#include <stddef.h>

typedef struct Queue
{
  void **data;
  size_t element_size;
  size_t size;
  size_t capacity;
} Queue;

Queue *createQueue(size_t element_size);
void pushQueue(Queue *queue, void *element);
void *popQueue(Queue *queue);
void clearQueue(Queue *queue);
int isEmptyQueue(Queue *queue);
size_t sizeQueue(Queue *queue);