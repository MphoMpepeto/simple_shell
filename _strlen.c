#include "shell.h"

/**
* _strlen - a funtion that determines the len of a string.
* @strng: string with chars to be counted.
* Return: Length of the string.
*/

int _strlen(char *strng)
{
	int length = 0;

	while (*strng != '\0')
	{
		length += 1;

		strng += 1;
	}

	return (length);
}
