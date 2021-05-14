#include "monty.h"

/**
 * _strlen - function returns the lenght of the string
 * @str: string passed
 * Return: length of string
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

/**
 * tokenizeInput - function tokenizes a string
 * @input: input to be tokenized
 * Return: 2D array of tokinized input
 */
char **tokenizeInput(char *input)
{
	char **inputArr, *temp, *hold;
	const char *space = " \n\t";
	int count = 0;

	inputArr = malloc(sizeof(char *) * 3);
	if (inputArr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	hold = strdup(input);
	temp = strtok(hold, space);

	while (temp != NULL && (count < 2))
	{
		inputArr[count] = strdup(temp);
		count++;
		temp = strtok(NULL, space);
	}
	inputArr[count] = NULL;
	free(hold);

	return (inputArr);
}

/**
 * freeDoublePointers - function fress a 2D array
 * @pointer: head node
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

/**
 * selectFunction - function assigns appropiate func pointer
 * @input: string to be compared
 * Return: func pointer
 */
void (*selectFunction(char *input))(stack_t **stack, unsigned int line_number)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"mul", mul},
		{"sub", sub},
		{"nop", nop},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	int idx = 0;

	while (function[idx].opcode)
	{
		if (strcmp(input, function[idx].opcode) == 0)
		{
			return (function[idx].f);
		}
		idx++;
	}
	return (function[idx].f);
}

/**
 * free_nodes - function frees a doubly linked list
 * @head: head node
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
