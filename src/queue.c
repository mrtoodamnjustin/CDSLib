#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Queue
// {
//   void **data;
//   size_t element_size;
//   size_t size;
//   size_t capacity;
// } Queue;

Queue *createQueue(size_t element_size)
{
  Queue *result = malloc(sizeof(Queue));

  result->data = malloc(0);

  result->element_size = element_size;
  result->size = 0;
  result->capacity = 0;

  return result;
}

void pushQueue(Queue *queue, void *element)
{
  void *newElement = malloc(queue->element_size);

  memcpy(newElement, element, queue->element_size);

  if (queue->size + 1 > queue->capacity)
  {
    int newCapacity = queue->capacity * 1.3 + 5;
    void **temp = realloc(queue->data, newCapacity * sizeof(void *));

    if (temp == NULL)
    {
      fprintf(stderr, "Memory allocation failure");
      exit(1);
    }

    queue->data = temp;
    queue->capacity = newCapacity;
  }

  queue->data[queue->size++] = newElement;
}

void *popQueue(Queue *queue)
{
  if (isEmptyQueue(queue))
    return NULL;

  void *popped = queue->data[0];

  for (size_t i = 1; i < queue->size; i++)
  {
    // Shift everything to the left
    queue->data[i - 1] = queue->data[i];
  }

  /* Since this element was shifted left, remove it
     from it's original spot */
  queue->data[queue->size - 1] = NULL;

  queue->size--;

  // Resize if the capacity is too high
  if (queue->size < queue->capacity / 4)
  {
    int newCapacity = queue->capacity / 2;
    void **temp = realloc(queue->data, newCapacity * sizeof(void **));

    if (temp == NULL)
    {
      fprintf(stderr, "Memory deallocation error");
      exit(1);
    }

    queue->data = temp;
    queue->capacity = newCapacity;
  }

  return popped;
}

void clearQueue(Queue *queue)
{
  for (size_t i = 0; i < queue->size; i++)
  {
    free(queue->data[i]);
  }

  queue->data = realloc(queue->data, 0);
  queue->capacity = 0;
  queue->size = 0;
}

int isEmptyQueue(Queue *queue)
{
  return queue->size == 0;
}

size_t sizeQueue(Queue *queue)
{
  return queue->size;
}