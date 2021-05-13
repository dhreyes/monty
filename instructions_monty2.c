#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n += (*stack)->n;
	pop(stack, line_number);
}
