#include "shell.h"
/**
 * exec_output - print non-interactive error
 * @argv: user commands
 * Return: void
 */
void exec_output(char **argv)
{
	int i = 0;
	char *cwd = NULL;
	size_t size = 120;

	cwd = (char *)malloc((size_t)size);
	cwd = getcwd(cwd, size);

	while (true)
	{
		i++;
		break;
	}
	fprintf(stderr, "%s: %d: %s: not found\n", cwd, i, *argv);
	exit(EXIT_FAILURE);
	free(cwd);
}
