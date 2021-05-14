#include "monty.h"
/**
 * pchar - prints the ascii char value
 * @stack: head of stack
 * @line_number: line count
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->n;

	if (number < 0 || number > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", number);
}

/**
 * pstr - prints the str of the value of the
 * @stack: head of stack
 * @line_number: line count
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int number;
	stack_t *str_candidate = *stack;

	if (*stack == NULL && (line_number > 0))
	{
		printf("\n");
		return;
	}

	while (str_candidate)
	{
		number = str_candidate->n;
		if (number <= 0 || number > 127)
		{
			break;
		}
		printf("%c", number);
		str_candidate = str_candidate->next;
	}
	printf("\n");
}

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

	if (stackLength(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		node_num_value = "ERROR";
		return;
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
