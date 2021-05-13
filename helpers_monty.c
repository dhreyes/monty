#include "monty.h"

/*
 *
 */
int _strlen(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

/*
 *
 */
char **tokenizeInput(char *input)
{
	char **inputArr, *temp, *hold;
	const char *space = " ";
	int count = 0;

	inputArr = malloc(sizeof(char *) * 3);
	if (inputArr == NULL) return NULL;

	hold = strdup(input);
	temp = strtok(hold, space);

	while ( temp!= NULL)
	{
		inputArr[count] = strdup(temp);
		count++;
		temp = strtok(NULL, space);
	}
	inputArr[count] = NULL;
	free(hold);

	return(inputArr);
}

/*
 *
 */
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

/*
 *
 */
void (*select_function(char *input))(stack_t **stack, unsigned int line_number)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
/*		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},*/
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
	return (function[idx].f);
}

/*
 *
 */
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
