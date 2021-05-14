#include "monty.h"

void inputError(char *inputArr[], stack_t **stack, unsigned int line);

/**
 * main - function reads instructions from a file and creates a stack
 * @argc: counts arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 1;
	int lastIndex;
	char input[1000], **inputArr;
	void (*func_ptr)(stack_t **, unsigned int) = NULL;
	stack_t *stack = NULL;

	FILE *fd = fopen(argv[1], "r");
		if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(input, sizeof(input), fd) != NULL)
	{
		lastIndex = (_strlen(input) - 1);
		input[lastIndex] = '\0'; /*removed \n char added by fgets*/

		if (_strlen(input) == 0)
			continue;

		inputArr = tokenizeInput(input);
		node_num_value = inputArr[1];

		func_ptr = selectFunction(inputArr[0]);
		if (!(func_ptr))
		{
			inputError(inputArr, &stack, line_number);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		func_ptr(&stack, line_number);

		if (node_num_value)
		{
			if (_strcmp("ERROR", node_num_value) == 0)
			{
				freeDoublePointers(inputArr);
				free_nodes(stack);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
		freeDoublePointers(inputArr);
		line_number++;
	}
	free_nodes(stack);
	fclose(fd);
	return (0);
}

/**
 * inputError - function prints error msg and exits
 * @inputArr: 2D array of input to free
 * @stack: linked list to free
 * @line: line count
 */
void inputError(char *inputArr[], stack_t **stack, unsigned int line)
{
	fprintf(stderr, "L%i: unknown instruction %s\n", line, inputArr[0]);
	freeDoublePointers(inputArr);
	free_nodes(*stack);
}
