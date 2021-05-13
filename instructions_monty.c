#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (line_number == 0)
		printf("nothing\n");

	if (atoi(node_num_value) == 0)
	{
		fprintf(stderr, "L%d: usage: push interger\n", line_number);
		/*NEED APPPRIATE FREES-> file, inputArr*/
		free_nodes(*stack);
		exit(EXIT_FAILURE);
	}

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
	    node->n = atoi(node_num_value);
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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		/*NEED TO FREE FILE/INPUTARR*/
		free_nodes(*stack);
		exit(EXIT_FAILURE);
	}

	if (line_number != '\0')
	{
		printf("%i\n", (*stack)->n);
	}
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_nodes(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}

/*
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
