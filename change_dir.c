#include "shell.h"

/**
 * change_dir - a function that changes the working directory
 * @dir: the new working directory
 * Return: 0 if successful
 */

int change_dir(const char *dir)
{
	char curr_dir[INPUT_SIZE];

	if (getcwd(curr_dir, sizeof(curr_dir)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (chdir(dir) != 0)
	{
		perror("chdir");
		return (-1);
	}
	if (setenv("PWD", dir, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	she_prints("%s\n", curr_dir);
	return (0);
}
