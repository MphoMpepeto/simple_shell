#include "shell.h"

/**
 * print_error - print error and exit with a status code.
 * Return: void
 */

void print_error(void)
{
	perror("error performing task");
	exit(1);
}
