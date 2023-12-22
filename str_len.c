#include "shell.h"

/**
 * str_len - a function that returns the length of a string
 * @s: a pointer to the string
 * Return: the length of the string.
 */

int str_len(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}
