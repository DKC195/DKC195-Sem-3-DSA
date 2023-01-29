// Lab 1: Implementation of Stack as an ADT
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define true 1
#define false 0

struct Stack
{
  int TOP;
  int data[MAX];
};

int isFull(struct Stack S)
{
  return (S.TOP == MAX - 1) ? true : false;
}

int isEmpty(struct Stack S)
{
  return (S.TOP == -1) ? true : false;
}

void push(struct Stack *S, int element)
{
  if (isFull(*S))
    printf("STACK OVERFLOW\n");
  else
  {
    S->TOP += 1;
    S->data[S->TOP] = element;
    printf("SUCCESS\n");
  }
}

int pop(struct Stack *S)
{
  if (isEmpty(*S))
  {
    printf("STACK UNDERFLOW");
    return -1;
  }
  else
  {
    return S->data[S->TOP--];
  }
}

int main()
{
  int choice, element;
  struct Stack AnyThing = {-1};
  // AnyThing.Top = -1
  do
  {
    printf("1. PUSH\n2. POP\n3. EXIT\n");
    printf("Choice? ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter Element: ");
      scanf("%d", &element);
      push(&AnyThing, element);
      break;

    case 2:
      printf("%d WAS POPPED\n", pop(&AnyThing));
      break;

    case 3:
      printf("BYE BYE\n");
      break;

    default:
      break;
    }
  } while (choice != 3);

  return 0;
}