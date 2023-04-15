// Implementing Queue using SLL
#include <stdio.h>
#include <stdlib.h>

struct SLL
{
  int data;
  struct SLL *next;
} *out, *in;

void enqueue(int element)
{
  struct SLL *NewNode;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  if (NewNode == NULL)
    printf("Memory Allocation Failed\n");
  else
  {
    NewNode->data = element;
    NewNode->next = NULL;
    if (in == NULL)
    {
      in = out = NewNode;
    }
    else
    {
      NewNode->next = in;
      in = NewNode;
    }
  }
}

int dequeue()
{
  struct SLL *temp;
  if (out == NULL)
  {
    printf("Queue Underflow\n");
    return -1;
  }
  else
  {
    int element = out->data;
    if (out->next == NULL)
    {
      temp = out;
      free(temp);
      out = NULL;
    }
    else
    {
      temp = out;
      free(out);
    }
    return element;
  }
}

int main()
{
  in = out = NULL;
  int choice, element;
  do
  {
    printf("1. Enqueue\n2. Dequeue\n3. EXIT\n");
    printf("Choice: \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter a value: ");
      scanf("%d", &element);
      enqueue(element);
      break;

    case 2:
      element = dequeue();
      printf("%d was dequeued", element);
      break;

    default:
      break;
    }
  } while (choice != 3);

  return 0;
}