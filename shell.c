#include "shell.h"

/**
 * main - this is the main function for my shell program.
 * Return: 0 on sucess.
 */

int main(void);

int main(void)
{
	char *getline_num, *pokemon, *prompt = "(Tom Mpho)$ ";

	char **argv;

	int i;

	int interactive_mode = isatty(fileno(stdin));
	
	char* semicolon_position;


	while (true)
	{
		switch (interactive_mode) 
		{
		       	case 1:
				_printf("%s", prompt);
				fflush(stdout);
				getline_num = my_getline();

				if (getline_num == NULL)
			       	{
					break;
        			}
       				 break;

    			case 0:
        			getline_num = non_interactive_reader();
			       
				if (getline_num == NULL) {
            				break;
        			}
        			break;

    			default:
        			break;
		}

		semicolon_position = strstr(getline_num, ";");

		if (semicolon_position != NULL) {
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

	      /*if (!interactive_shell)
		{
			break;
		} */
	}

	return (0);
}
