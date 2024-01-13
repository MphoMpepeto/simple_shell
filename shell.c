#include "shell.h"

/**
 * main - the entry point shell program.
 * Return: 0 on sucess.
 */

int main(void);

int main(void)
{
	bool interactive_mode;

	char *getline_num;

	char **argv;

	char *pokemon;

	int i;

	char *prompt = "(Simple Hell)$ ";

	interactive_mode = isatty(fileno(stdin));


	while (1)
	{

		if (interactive_mode)
		{
			she_prints("%s", prompt);

			fflush(stdout);

			getline_num = my_getline();

			if (getline_num == NULL)
			{
				break;
			}

		}
		else
		{
			getline_num = non_interactive_reader();

			if (getline_num == NULL)
			{

				break;
			}
		}

		if (strstr(getline_num, ";") != NULL)
		{

			free(getline_num);
			continue;
		}
		argv = malloc(sizeof(char *) * (PEAK_ARGS + 1));

		if (argv == NULL)
		{
			perror("Failed to Allocate Memory");
			exit(EXIT_FAILURE);
		}


		i = 0;

		pokemon = str_tok(getline_num, " \t\r\n\a");

		while (pokemon != NULL && i < PEAK_ARGS)
		{
			argv[i] = pokemon;

			i++;

			pokemon = str_tok(NULL, " \t\r\n\a");
		}

		argv[i] = NULL;

		if (i == 0)
		{
			free(getline_num);
			free(argv);

			continue;
		}

		yenza_command(argv, getline_num);

		free(getline_num);
		free(argv);

		if (!interactive_mode)
		{
			break;
		}
	}

	return (0);
}
