#include "monty.h"

int main(__attribute__((unused))int argc, char **argv)
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

	while(fgets(input, sizeof(input), fd) != NULL)
	{
		lastIndex = (_strlen(input) - 1);
		input[lastIndex] = '\0'; /*removed \n char added by fgets*/

		inputArr = tokenizeInput(input);
		node_num_value = inputArr[1];

		func_ptr = select_function(inputArr[0]);
		func_ptr(&stack, line_number);

		freeDoublePointers(inputArr);
		line_number++;
	}

	free_nodes(stack);
	fclose(fd);
	return (0);
}
/**
 *  * _atoi - turn string to int
 *   * @s: string to be converted
 *    * Return: Converted num
 *     */
int _atoi(char *s)
{
	int i = 0, len = 0, num = 0, sign = 1, ok = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	while (i < len && ok == 0)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + sign * (s[i] - 48);
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
				ok = 0;
			else
				ok = 1;
		}
		i++;
	}
	return (num);
}
