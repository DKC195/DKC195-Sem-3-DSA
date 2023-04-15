// Implementing SLL
#include <stdio.h>
#include <stdlib.h>

struct SLL
{
  int data;
  struct SLL *next;
} *top;

void push(int element)
{
  struct SLL *NewNode;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  if (NewNode == NULL)
    printf("Memory Allocation Failed\n");
  else
  {
    NewNode->data = element;
    NewNode->next = NULL;
    if (top == NULL)
    {
      top = NewNode;
    }
    else
    {
      NewNode->next = top;
      top = NewNode;
    }
    printf("Success\n");
  }
}

int pop()
{
  struct SLL *temp;
  if (top == NULL)
  {
    printf("Stack Underflow\n");
    return -1;
  }
  else
  {
    int element = top->data;
    if (top->next == NULL)
    {
      temp = top;
      free(temp);
      top = NULL;
    }
    else
    {
      temp = top;
      top = top->next;
      free(temp);
    }
    return element;
  }
}

int main()
{
  top = NULL;
  int choice, element;
  do
  {
    printf("1. PUSH\n2. POP\n3. EXIT\n");
    printf("Choice: \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter a value: ");
      scanf("%d", &element);
      push(element);
      break;

    case 2:
      element = pop();
      printf("%d was popped\n", element);
      break;

    default:
      break;
    }


  } while (choice != 3);

  return 0;
}