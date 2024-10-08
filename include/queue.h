#pragma once

#include <stddef.h>

typedef struct Queue
{
  void **data;
  size_t element_size;
  size_t size;
  size_t capacity;
} Queue;

Queue *queue_create(size_t element_size);
void queue_push(Queue *queue, void *element);
void *queue_pop(Queue *queue);
void queue_clear(Queue *queue);
int queue_is_empty(Queue *queue);
size_t queue_size(Queue *queue);