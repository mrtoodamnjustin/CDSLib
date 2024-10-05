#pragma once
#include <stddef.h>

typedef struct Stack
{
  void **data;
  size_t size;
  size_t capacity;
  size_t element_size;
} Stack;

Stack *createStack(size_t element_size);
void destroyStack(Stack *stack);
void pushStack(Stack *stack, void *element);
void popStack(Stack *stack);
void clearStack(Stack *stack);
void *topStack(Stack *stack);
size_t sizeStack(Stack *stack);
int isEmptyStack(Stack *stack);