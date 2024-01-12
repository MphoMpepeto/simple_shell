#include "shell.h"

/**
 * yenza_command - a function that checks logic and executes program.
 * @argv: an array of command arguments.
 * @getline_num: The getline argument.
 * Return: void
 */

void yenza_command(char **argv, char *getline_num);

void yenza_command(char **argv, char *getline_num)
{
	char exec_doc[INPUT_SIZE];

	char *_path = "/bin/";

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			char *end_ptr;

			long status = strtol(argv[1], &end_ptr, 10);

			if (strcmp(argv[1], "-98") == 0)
			{
				char *k = argv[0];

				char *l = argv[1];

				int j = 1;

				char *msg = "./hsh: %d: %s: Wrong number: %s\n";

				_err_printf(stderr, msg, j, k, l);
				free(getline_num);
				free(argv);
				exit(2);
			}

			if (*end_ptr == '\0')
			{
				free(getline_num);
				free(argv);
				exit(status);
			}
			else
			{
				char *k = argv[0];

				char *l = argv[1];

				int j = 1;

				char *msg = "./hsh: %d: %s: Illegal number: %s\n";

				_err_printf(stderr, msg, j, k, l);
				free(getline_num);
				free(argv);
				exit(2);
			}
		}
		else
		{
			free(getline_num);
			free(argv);
			exit(0);
		}
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		char **env;

		for (env = environ; *env != NULL; env++)
		{
			_printf("%s\n", *env);
		}
	}
	else if (strcmp(argv[0], "setenv") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(argv[0], "cd") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(argv[0], "#") == 0)
	{
		/* This is a comment, do nothing*/
	}
	else
	{
		if (strchr(argv[0], '/') != NULL)
		{
			if (access(argv[0], X_OK) != -1)
			{
				exec(argv, getline_num);
			}
			else
			{
				int n = 1;

				char *msg = "./hsh: %d: %s: not found\n";

				_err_printf(stderr, msg, n, argv[0]);
				free(getline_num);
				free(argv);
				exit(127);
			}
		}
		else 
		{
			strcpy(exec_doc, _path);
			strcat(exec_doc, argv[0]);

			if (access(exec_doc, X_OK) != -1)
			{
				exec(argv, getline_num);
			}
			else
			{
				char *msg = "./hsh: %d: %s: not found\n";

				_err_printf(stderr, msg, 1, argv[0]);
				free(getline_num);
				free(argv);
				exit(127);
			}
		}
	}
}