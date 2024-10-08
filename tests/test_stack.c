#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Usage: test_stack.exe <num_1> <num_2> ... <num_n>");
    return 1;
  }

  Stack *stack = stack_create(sizeof(int));

  for (int i = 1; i < argc; i++)
  {
    stack_push(stack, &(int){atoi(argv[i])});
  }

  printf("Lets flush your stack!\n");

  while (!stack_is_empty(stack))
  {
    printf("Current number of elements: %d\n", stack_size(stack));

    int *popped = stack_pop(stack);
    printf("Popped %d\n\n", *popped);
    free(popped);
  }

  printf("No elements are left!\n");

  stack_destroy(stack);

  return 0;
}