#include "shell.h"
/**
 * check_malloc - check status of memory allocation
 * @variable: variable to be allocated memory
 * Return: nothing
 */

void check_malloc(char **variable)
{
	if (sizeof(variable) == sizeof(char **) && variable == NULL)
	{
		perror("Memory allocation failure\n");
		exit(EXIT_FAILURE);
	}
}


