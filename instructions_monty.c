#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (line_number == 0)
		printf("nothing\n");

	node = malloc(sizeof(stack_t));
		if (node == NULL) printf("malloc failed\n");

	if (*stack == NULL)
	{
	    node->n = atoi(node_num_value);
		node->prev = NULL;
		node->next = NULL;
		*stack = node;
	}
	else
	{
	    node->n = _atoi(node_num_value);
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev = node;
		*stack = node;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (line_number == '\0' && *stack != NULL)
		printf("error\n");

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (line_number != '\0')
	{
		printf("%i\n", (*stack)->n);
	}
}
