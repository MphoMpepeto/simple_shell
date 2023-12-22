#include "shell.h"
/**
 * ye_commd - a fucntion that runs commands
 * @nipa_input: user input in a string format
 * @argv: a list or arguments from user
 * @pokemon: tokenized user input
 * @delimetr: a delimeter used in tokenization
 *
 */

void ye_commd(char *nipa_input, char **argv, char *pokemon, char *delimetr)
{
	int i = 0;

	pokemon = strtok(nipa_input, delimetr);

	while (pokemon != NULL)
	{
		argv[i] = malloc(strlen(pokemon) + 1);
		if (argv[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		str_copy(argv[i], pokemon);
		pokemon = strtok(NULL, delimetr);
		i++;
	}
	argv[i] = NULL;
	handl_path_commd(argv);
/*	free_argv(argv);*/
}
