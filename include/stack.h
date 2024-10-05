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
Stack *createStack(size_t element_size);

/* Frees all memory occupied by the stack */
void destroyStack(Stack *stack);

/* Pushes the element to the top, and dynamically
  reallocates the capacity if necessary */
void pushStack(Stack *stack, void *element);

/* Returns a pointer to the top in memory.
  It is the programmer's responsibility to free
  that memory once they're done using it */
void *popStack(Stack *stack);

/* Returns the stack to it's default empty state */
void clearStack(Stack *stack);

/* Returns a pointer to the top of the stack */
void *topStack(Stack *stack);

/* Returns the size of the stack */
size_t sizeStack(Stack *stack);

/* Returns whether the stack is empty */
int isEmptyStack(Stack *stack);