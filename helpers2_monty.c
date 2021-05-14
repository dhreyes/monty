#include "monty.h"

/**
 * _strcmp - function compares two strings
 * @s1: pointer
 * @s2: pointer
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int count;

	if (s1 == NULL || s2 == NULL)
	{
		return (1);
	}

	for (count = 0; s1[count] != '\0' || s2[count] != '\0'; count++)
	{
		if (s1[count] != s2[count])
			return (1);
	}
	return (0);
}

/**
 * _isdigit - function evaluates wheter c is a number
 * @c: number valued
 *
 * Return: returns 1 if digit, 0 if otherwise
 */
int _isdigit(char *str)
{
	int idx;

	for (idx = 0; str[idx] != '\0'; idx++)
	{
		if (str[idx] < 48 || str[idx] > 57)
		{
			return (0);
		}
	}
	return (1);
}
