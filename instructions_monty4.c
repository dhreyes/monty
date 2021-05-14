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

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
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