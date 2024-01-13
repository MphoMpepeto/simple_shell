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
			she_prints("%s\n", *env);
		}
	}
	else if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
		{
			_err_printf(stderr, "Usage: setenv VARIABLE VALUE\n");
			return ;
		}
		if (setenv(argv[1], argv[2], 1) != 0)
		{
			perror("setenv");
		}
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] == NULL || argv[2] != NULL)
		{
			_err_printf(stderr, "Usage: unsetenv VARIABLE\n");
			return ;
		}
		if (unsetenv(argv[1]) != 0)
		{
			perror("unsetenv");
		}
	}
	else if (strcmp(argv[0], "cd") == 0)
	{
		const char *dir;

		dir = (argv[1] != NULL) ? argv[1] : getenv("HOME");
		if (change_dir(dir) != 0)
		{
			_err_printf(stderr, "cd: %s: No such direectory\n", dir);
		}
	}
	else if (strcmp(argv[0], "#") == 0)
	{
		if (argv[0][0] == '#')
		{
                	return ;
		}
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
