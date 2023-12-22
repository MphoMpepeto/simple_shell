#include "shell.h"

/**
 * she_prints - a function that prints a string
 * @printee: the string to be printed
 *
 */

void she_prints(const char *printee)
{
	int x;

	for (x = 0; printee[x] != '\0'; x++)
	{
		write(1, &printee[x], 1);
	}
}
