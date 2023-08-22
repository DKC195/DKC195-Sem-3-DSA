#include <stdio.h>

#define N 5

struct stack
{
  int n[N];
  int top;
};

void push(struct stack *s, int val);
void pop(struct stack *s);
void show(struct stack *s);
void tos(struct stack *s);

int main()
{
  int c, val;
  struct stack s;
  s.top = -1;
  do
  {
    printf("\nSTACK IMPLEMENTATION USING ARRAY");
    printf("\nEnter\n1. Push\n2. Pop\n3. Show All\n4. Top of Stack\nEnter any other key to exit: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      printf("Enter a number to push: ");
      scanf("%d", &val);
      push(&s, val);
      break;

    case 2:
      pop(&s);
      break;

    case 3:
      show(&s);
      break;

    case 4:
      tos(&s);
      break;

    default:
      c = 5;
      break;
    }
  } while (c != 5);
  return 0;
}

void push(struct stack *s, int val)
{
  if (s->top == N - 1)
    printf("\nStack is Full");
  else
  {
    s->top++;
    s->n[s->top] = val;
    printf("\n%d is pushed", s->n[s->top]);
  }
}

void pop(struct stack *s)
{
  if (s->top == -1)
    printf("\nStack is Empty");
  else
  {
    printf("\nPop Value is %d", s->n[s->top]);
    s->top--;
  }
}

void show(struct stack *s)
{
  if (s->top == -1)
    printf("\nStack is Empty");
  else
    for (int i = s->top; i <= 0; i--)
      printf("\n%d", s->n[i]);
}

void tos(struct stack *s)
{
  if (s->top == -1)
    printf("\nStack is Empty, Underflow");
  else
    printf("\nTop Value is %d", s->n[s->top]);
}