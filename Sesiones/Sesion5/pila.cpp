#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 10
int stack_size = 0;

typedef struct
{
  int items[MAX];
  int top;
} stack;

void createEmptyStack(stack *s)
{
  s->top = -1;
}

int isFull(stack *s)
{
  if (s->top == MAX - 1)
  {
    return 1;
  }
  else
    return 0;
}

int isEmpty(stack *s)
{
  if (s->top == -1)
  {
    return 1;
  }
  else
    return 0;
}

void push(stack *s, int newItem)
{
  if (isFull(s))
  {
    cout << "STACK FULL" << endl;
    return;
  }
  else
  {
    s->top++;
    s->items[s->top] = newItem;
  }
  stack_size++;
}

void pop(stack *s)
{
  if (isEmpty(s))
  {
    cout << "STACK VACIO" << endl;
  }
  else
  {
    cout << "Item sacado= " << s->items[s->top] << endl;
    s->top--;
  }
  stack_size--;
}

void printStack(stack *s)
{
  cout << "Stack: ";
  for (int i = 0; i < stack_size; i++)
  {
    cout << s->items[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  int ch;
  stack *s = (stack *)malloc(sizeof(stack));
  createEmptyStack(s);
  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  cout << "Después de pop:" << endl;
  printStack(s);

  free(s);

  return 0;
}
