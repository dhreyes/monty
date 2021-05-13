#include "monty.h"

void freeDoublePointers(char **pointer)
{
	int count, numOfPtrsToFree = 0;

	for (count = 0; pointer[count] != NULL; count++)
	{
		numOfPtrsToFree++;
	}

	for (; numOfPtrsToFree >= 0; numOfPtrsToFree--)
	{
		free(pointer[numOfPtrsToFree]);
	}

	free(pointer);
}

int _strlen(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

stack_t *initNode(stack_t *node, stack_t *head, int num)
{
	stack_t *temp = head;

	if (head->n == '\0')
	{
		head->n = num;
		head->prev = NULL;
		head->next = NULL;
	
		return (head);
	}
	else
	{
		node = malloc(sizeof(stack_t));
			if (node == NULL) return NULL;

		node->n = num;
		node->next = NULL;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
		node->prev = temp;
		return (node);
	}
}


void free_nodes(stack_t *head)
{
	stack_t *pointer;

	while (head != NULL)
	{
		pointer = head->next;
		free(head);
		head = pointer;
	}
}

void (*select_function(char *input))(stack_t **stack, unsigned int line_number)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int idx = 0;
	/* Iterates through the array of functions (strings) */
	while (function[idx].opcode)
	{
		/* checks for matching string to input being passed */
		if (strcmp(input, function[idx].opcode) == 0)
		{
			/* Calls matching function paired with string */
			return (function[idx].f);
		}
		idx++;
	}
	printf("L<line_number>: unknown instruction <opcode>\n");
	exit(EXIT_FAILURE);
}

