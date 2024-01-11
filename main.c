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
				getline_num = cstm_getline();

				if (getline_num == NULL)
			       	{
					break;
        			}
       				 break;

    			case 0:
        			getline_num = cstm_non_interactive_getline();
			       
				if (getline_num == NULL) {
            				break;
        			}
        			break;

    			default:
        			break;
		}

		/*Check if multiple commands were enetered*/
		semicolon_position = strstr(getline_num, ";");

		if (semicolon_position != NULL) {
    			free(getline_num);
    			continue;
		}

		/*Dynamically Allocate memory for the arguments to be executed*/
		argv = malloc(sizeof(char *) * (MAX_ARGS + 1));

		if (argv == NULL)
		{
			perror("Failed to Allocate Memory");
			exit(EXIT_FAILURE);
		}

		i = 0;
		pokemon = cstm_strtok(getline_num, " \t\r\n\a");

		while (pokemon != NULL && i < MAX_ARGS)
		{
			argv[i] = pokemon;
			i++;
			pokemon = cstm_strtok(NULL, " \t\r\n\a");
		}

		argv[i] = NULL;

		if (i == 0)
		{
			free(getline_num);
			free(argv);

			continue;
		}

		execute_builtin_command(argv, getline_num);

		free(getline_num);
		free(argv);

	      /*if (!interactive_shell)
		{
			break;
		} */
	}

	return (0);
}
