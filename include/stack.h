#pragma once
#include <stddef.h>

typedef struct Stack
{
  void **data;
  size_t size;
  size_t capacity;
  size_t element_size;
} Stack;

/* Allocate space for the stack, and
  prepares it to be used
  Returns a pointer to the stack */
Stack *stack_create(size_t element_size);

/* Frees all memory occupied by the stack */
void stack_destroy(Stack *stack);

/* Pushes the element to the top, and dynamically
  reallocates the capacity if necessary */
void stack_push(Stack *stack, void *element);

/* Returns a pointer to the top in memory.
  It is the programmer's responsibility to free
  that memory once they're done using it */
void *stack_pop(Stack *stack);

/* Returns the stack to it's default empty state */
void stack_clear(Stack *stack);

/* Returns a pointer to the top of the stack */
void *stack_top(Stack *stack);

/* Returns the size of the stack */
size_t stack_size(Stack *stack);

/* Returns whether the stack is empty */
int stack_is_empty(Stack *stack);