#include "monty.h"

int main(__attribute__((unused))int argc, char **argv)
{
	unsigned int line_number = 0;
	char input[128], **inputArr;
	int lastIndex;
	void (*func_ptr)(stack_t **, unsigned int) = NULL;
	stack_t **stack, *head;

	/*opens file*/
	FILE *fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		perror("unable to open fil\n");
		exit(1);
	}

	head = calloc(1, sizeof(stack_t));
		if (head == NULL) exit(1);

	/*reads file until it reaches EOF*/
	while (fgets(input, sizeof(input), fd) != NULL)
	{
		lastIndex = (_strlen(input) - 1); /*gets the last index of input*/
		input[lastIndex] = '\0'; /*removes '\n' character added by fgets*/

		inputArr = tokenizeInput(input); /*returns tokinizes input*/
		func_ptr = select_function(inputArr[0]);
		if (strcmp(inputArr[0], "push") == 0)
		{
			stack =(stack_t **)initNode(*stack, head, atoi(inputArr[1]));
		}
		func_ptr(stack, line_number);
		freeDoublePointers(inputArr);

		line_number++;
	}

	free_nodes(head);
	fclose(fd);
	return (0);
}
