#include "monty.h"

/**
 * add - function adds two nodes
 * @stack: head node
 * @line_number: line count
 */
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

/**
 * sub - function subtracts two nodes
 * @stack: head node
 * @line_number: line count
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	}
	temp = (*stack)->next;
	temp->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - function multiplies two nodes
 * @stack: head node
 * @line_number: line count
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	}
	temp = (*stack)->next;
	temp->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides two nodes
 * @stack: head node
 * @line_number: line count
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
	}
	temp = (*stack)->next;
	temp->n = temp->n / (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - function modulates two nodes and finds remainder
 * @stack: head node
 * @line_number: line count
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
	}
	temp = (*stack)->next;
	temp->n = temp->n % (*stack)->n;
	pop(stack, line_number);
}
