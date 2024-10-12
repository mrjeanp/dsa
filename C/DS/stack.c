#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct StackNode
{
  void *data;
  struct StackNode *below;

} StackNode;

typedef struct Stack
{
  StackNode *top;
  unsigned size;
  unsigned capacity;

} Stack;

Stack *stack_new(unsigned capacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->size = 0;
  return stack;
}

bool stack_is_full(Stack *stack)
{
  return stack->capacity != 0 && stack->capacity == stack->size;
}

void stack_push(Stack *stack, void *data)
{
  if (stack_is_full(stack))
  {
    printf("Stack overflow\n");
    return;
  }

  stack->top = (StackNode *)malloc(sizeof(StackNode));
  stack->top->data = data;
  stack->size++;
}

bool stack_is_empty(Stack *stack)
{
  return stack->size == 0;
}

void *stack_pop(Stack *stack)
{

  if (stack_is_empty(stack))
  {
    printf("Stack underflow\n");
    return NULL;
  }

  StackNode *top = stack->top;
  void *data = top->data;

  stack->top = stack->top->below;

  stack->size--;

  free(top);

  return data;
}

void *stack_peek(Stack *stack)
{
  if (stack_is_empty(stack))
  {
    printf("Stack is empty\n");
    return NULL;
  }
  return stack->top->data;
}

void stack_free(Stack *stack)
{
  StackNode *node = stack->top;

  while (node != NULL)
  {
    void *data = stack_pop(stack);

    free(data);

    node = stack->top;
  }

  free(stack);
}
