#include "shell.h"

/**
 * exit_shell - a function that exits the shell
 * @nipa_input: A pointer to the input received from the user
 */

void exit_shell(char *nipa_input)
{
	if (str_cmp(nipa_input, "exit") == 0)
	{
		exit(0);
	}
}
