#include "shell.h"
/**
 * handl_path_commd - create env path and execute command
 * @argv: double pointer to argument list of users input
 * Return: nothing;
 */
void handl_path_commd(char **argv)
{
	char *command = NULL, *path = getenv("PATH"), *path_poken, *full_path;
	char *search = str_chr(argv[0], '/');
	char *copy_path;

	copy_path = (char*)malloc(strlen(path) + 1);
	str_copy(copy_path, path);
	if (search != NULL)
	{
		command = argv[0];
	}
	else
	{
		path_poken = strtok(copy_path, ":");
		if (path_poken == NULL)
		{
			perror("you entered a wrong path");
			exit(EXIT_FAILURE);
		}
		while (path_poken != NULL)
		{
			full_path = (char*)malloc(strlen(path_poken) + 2 + strlen(argv[0]));
			check_malloc(&full_path);
			str_copy(full_path, path_poken);
			str_concat(full_path, "/");
			str_concat(full_path, argv[0]);
			if (access(full_path, X_OK) == 0)
			{
				command = full_path;
				break;
			}
			free(full_path);
			path_poken = strtok(NULL, ":");
		}
	}
	if (execve(command, argv, NULL) == -1)
	{
		exec_output(argv);
	}
	free(copy_path);
	/*free(full_path);*/
}

