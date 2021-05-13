#include "monty.h"


/**
 * getInput
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
