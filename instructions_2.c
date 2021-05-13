#include "monty.h"
/**
 *
 *
 */
void nop(stack_t *stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

void add(stack_t *stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || stack->prev == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = stack->prev;
	temp->n += stack->n;
	printf("This is the addition res:<%d> \n", stack->n);
	/* pop on top stack */
	/*pop(stack, line_number);*/
}

void swap(stack_t *stack, unsigned int line_number)
{
	stack_t *swap1 = stack;
	stack_t *swap2;

	if (stack == NULL || stack->prev == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	swap2 = stack->prev;
	if (swap2->prev == NULL)
	{
		swap2->prev = swap1;
		swap2->next = NULL;
		swap1->prev = NULL;
		swap1->next = swap2;
		stack = swap2;
	}
	else
	{
		swap2->prev->next = swap1;
		swap1->prev = swap2->prev;
		swap1->next = swap2;
		swap2->prev = swap1;
		swap2->next = NULL;
		stack = swap2;
	}
}

