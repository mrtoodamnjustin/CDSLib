#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Usage: test_queue.exe <char_1> <char_2> ... <char_n>");
    return 1;
  }

  Queue *queue = queue_create(sizeof(char *));

  for (int i = 1; i < argc; i++)
  {
    queue_push(queue, &(int){atoi(argv[i])});
  }

  printf("Lets flush your queue!\n");

  while (!queue_is_empty(queue))
  {
    printf("Current size of queue: %d\n", queue_size(queue));

    int *popped = (int *)queue_pop(queue);
    printf("Popped %d\n\n", *popped);
    free(popped);
  }

  printf("Your queue has been flushed!");
  return 0;
}