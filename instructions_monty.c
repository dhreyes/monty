#include "monty.h"

/**
 * push - function adds node
 * @stack: head node
 * @line_number: line count
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	(void)line_number;

	if ((atoi(node_num_value) == 0 && (strcmp(node_num_value, "0") != 0))
		|| (_isdigit(node_num_value) == 0))
	{
		fprintf(stderr, "L%d: usage: push interger\n", line_number);
		node_num_value = "ERROR";
	}
	else
	{
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

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
}

/**
 * pall - function prints node
 * @stack: head node
 * @line_number: line count
 */
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


/**
 * pint - function prints top node
 * @stack: head node
 * @line_number: line count
 */
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

/**
 * pop - function removes node
 * @stack: head node
 * @line_number: line count
 */
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

/**
 * nop - function does nothing
 * @stack: head node
 * @line_number: line count
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
