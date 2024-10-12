
#include "../stack.c"
#include <stdio.h>

int main()
{
  Stack *stack = stack_new(0);
  stack_push(stack, "heh");
  printf("top of stack %s", (char *)stack_peek(stack));

  return 0;
}
