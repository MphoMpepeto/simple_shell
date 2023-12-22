#include "shell.h"

/**
 *
 */

void erro_mgs(char *counter, char *argv)
{
	/* ./hsh: 1: qwerty: not found */
	char error_msg[7][20];
	char *cwd = NULL;
	char end_msg[] = "not found";
	char colon[] = ": ";
	size_t size = 10;
	int i;
	cwd = (char *)malloc((size_t)size);
       
	char *after_pipe = getcwd(cwd, size);
	
	str_copy(error_msg[0], after_pipe);
	str_copy(error_msg[1], colon);
	str_copy(error_msg[2], (char *)counter);
	str_copy(error_msg[3], colon);
	str_copy(error_msg[4], argv);
	str_copy(error_msg[5], colon);
	str_copy(error_msg[6], end_msg);

	for (i = 0; i < 8; i++)
	{
		write(2, error_msg[i], strlen(error_msg[i]));
	}

}

int main(void)
{
	char *counter = "1";
	char *argv = "ls";

	if (execve(argv, &argv, NULL) == -1)
	{
	   erro_mgs(counter, argv);
	}
	return (0);
}

