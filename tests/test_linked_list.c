#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_int(void *num)
{
  printf("%d", *(int *)num);
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Usage: linked_lists.exe <num_1> <num_2> ... <num_n>");
    return 1;
  }

  int nodes = argc - 1;

  Node *head = ll_create(nodes, sizeof(int));

  Node *currentNode = head;
  for (int i = 0; i < nodes; i++)
  {
    *(int *)currentNode->data = atoi(argv[i + 1]);
    currentNode = currentNode->next;
  }

  ll_display(head, &print_int, " -> ");

  ll_free(head);

  return 0;
}