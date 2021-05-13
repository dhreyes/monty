#include "monty.h"
/**
 * swap - swaps top 2 stack values
 * @stack: head of double linked list
 * @line_number: tracks what line monty file is reading from
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *swap1 = *stack;
	stack_t *swap2;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	}

	swap2 = (*stack)->next;
	if (swap2->next == NULL)
	{
		swap2->next = swap1;
		swap2->prev = NULL;
		swap1->next = NULL;
		swap1->prev = swap2;
		*stack = swap2;
	}
	else
	{
		swap2->next->prev = swap1;
		swap1->next = swap2->next;
		swap1->prev = swap2;
		swap2->next = swap1;
		swap2->prev = NULL;
		*stack = swap2;
	}
}
