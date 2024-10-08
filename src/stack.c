#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Stack
// {
//   void **data;
//   size_t size;
//   size_t capacity;
//   size_t element_size;
// } Stack;

Stack *stack_create(size_t element_size)
{
  Stack *result = malloc(sizeof(Stack));
  result->data = malloc(0);
  result->capacity = 0;
  result->size = 0;
  result->element_size = element_size;

  return result;
}

void stack_destroy(Stack *stack)
{
  for (size_t i = 0; i < stack->size; i++)
  {
    free(stack->data[i]);
  }

  free(stack->data);
  free(stack);
}

void stack_push(Stack *stack, void *element)
{
  void *newElement = malloc(stack->element_size);

  memcpy(newElement, element, stack->element_size);

  size_t newCapacity = stack->capacity * 1.3 + 5;

  if (stack->size + 1 > stack->capacity)
  {
    void **temp = realloc(stack->data, newCapacity * sizeof(void *));

    if (temp == NULL)
    {
      fprintf(stderr, "Memory allocation failure");
      exit(1);
    }

    stack->data = temp;
    stack->capacity = newCapacity;
  }

  // Push the element, post-increment the size
  stack->data[stack->size++] = newElement;
}

void *stack_pop(Stack *stack)
{
  void *top = stack->data[stack->size - 1];

  stack->size--;

  if (stack->size < stack->capacity / 4)
  {
    size_t newCapacity = stack->capacity / 2;
    void **temp = realloc(stack->data, newCapacity * sizeof(void *));

    if (temp == NULL)
    {
      fprintf(stderr, "Memory deallocation error");
      exit(1);
    }

    stack->data = temp;
    stack->capacity = newCapacity;
  }

  return top;
}

void stack_clear(Stack *stack)
{
  for (size_t i = 0; i < stack->size; i++)
  {
    free(stack->data[i]);
  }

  stack->data = realloc(stack->data, 0);
  stack->size = 0;
  stack->capacity = 0;
}

void *stack_top(Stack *stack)
{
  return stack->data[stack->size - 1];
}

size_t stack_size(Stack *stack)
{
  return stack->size;
}

int stack_is_empty(Stack *stack)
{
  return stack->size == 0;
}