#include <stdio.h>

#include "binary_tree.h"

void display(void *data)
{
  printf("%d ", *(int *)data);
}

void pre_order(btNode *head, void (*func)(void *data))
{
  if (head == NULL)
    return;

  func(head->data);
  pre_order(head->left, func);
  pre_order(head->right, func);
}

void in_order(btNode *head, void (*func)(void *data))
{
  if (head == NULL)
    return;

  in_order(head->left, func);
  func(head->data);
  in_order(head->right, func);
}

void post_order(btNode *head, void (*func)(void *data))
{
  if (head == NULL)
    return;

  post_order(head->left, func);
  post_order(head->right, func);
  func(head->data);
}

int main()
{
  btNode *node1 = bt_create_node(&(int){7}, sizeof(int));
  btNode *node2 = bt_create_node(&(int){3}, sizeof(int));
  btNode *node3 = bt_create_node(&(int){9}, sizeof(int));

  node1->left = node2;
  node1->right = node3;

  printf("Pre-order: ");
  pre_order(node1, &display);
  printf("\nIn-order: ");
  in_order(node1, &display);
  printf("\nPost-order: ");
  post_order(node1, &display);
}