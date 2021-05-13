#include "monty.h"

void push(stack_t *stack, unsigned int line_number)
{
	if (stack == NULL)
		printf("stack is null %i\n", line_number);
}

void pall(stack_t *stack, unsigned int line_number)
{
	while(stack != NULL && line_number != '\0')
	{
		printf("%i\n", stack->n);
		stack = stack->prev;
	}
}

void pint(stack_t *stack, unsigned int line_number)
{
	if (line_number != '\0')
	{
		printf("%i\n", stack->n);
	}
}

/*void pop(stack_t *stack, unsigned int line_number)
{
	stack_t *temp = stack->next;


}*/
