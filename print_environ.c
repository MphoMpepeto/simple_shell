#include "shell.h"

/**
 * print_environ - a function that prints the current environment
 */

void print_environ(void)
{
	char **env = environ;
	size_t _strlen;

	while (*env != NULL)
	{
		_strlen = str_len(*env);
		write(1, *env, _strlen);
		write(1, "\n", 1);
		env++;
	}
}

