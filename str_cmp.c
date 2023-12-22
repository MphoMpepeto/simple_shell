#include "shell.h"

/**
 * str_cmp - a function that compares two strings
 * @s1: a pointer to the first string to be compared
 * @s2: a pointer to the second string to be compared
 * Return: always zero if successful
 */

int str_cmp(char *s1, char *s2)
{
	int d;

	for (d = 0; s1[d] != '\0' || s2[d] != '\0'; d++)
	{
		if (s1[d] != s2[d])
		{
			if (s1[d] != s2[d])
				return (s1[d] - s2[d]);
		}
	}
	return (0);
}

