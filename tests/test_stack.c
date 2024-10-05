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

  Stack *stack = createStack(sizeof(int));

  for (int i = 1; i < argc; i++)
  {
    pushStack(stack, &(int){atoi(argv[i])});
  }

  printf("Lets flush your stack!\n");

  while (!isEmptyStack(stack))
  {
    printf("Current number of elements: %d\n", sizeStack(stack));
    printf("Popped %d\n\n", *(int *)topStack(stack));
    popStack(stack);
  }

  printf("No elements are left!\n");

  destroyStack(stack);

  return 0;
}