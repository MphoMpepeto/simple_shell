#include "shell.h"

/**
* exec - A function that executes the given command.
* @args: Command line arguments to execute
* @getline_num: the getline value.
*/

void exec(char *args[], char *getline_num);

void exec(char *args[], char *getline_num)
{
	pid_t pid_fork_val;

	int wt_status;

	pid_fork_val = fork();

	if (pid_fork_val == -1) 
	{
		perror("Fork Error");

		free(getline_num);
		free(args);

		exit(EXIT_FAILURE);
	}

	if (pid_fork_val == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error from execve");
				free(getline_num);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = cstm_getenv("PATH");
			char *pokemon = str_tok(path, ":");

			while (pokemon != NULL)
			{
				char exec_doc[INPUT_SIZE];

				strcpy(exec_doc, pokemon);
				strcat(exec_doc, "/");
				strcat(exec_doc, args[0]);

				if (access(exec_doc, X_OK) != -1)
				{
					execve(exec_doc, args, environ);
				}

				pokemon = str_tok(NULL, ":");
			}
			_err_printf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
			free(getline_num);
			free(args);
			exit(127);
		}
	}
	else
	{
		do {
			waitpid(pid_fork_val, &wt_status, 0);

			if (WIFEXITED(wt_status))
			{
				free(getline_num);
				free(args);
				exit(WEXITSTATUS(wt_status));
			}
			if (WIFSIGNALED(wt_status))
			{
				raise(WTERMSIG(wt_status));
			}
		} while (WIFEXITED(wt_status) && WIFSIGNALED(wt_status));
	}
}
