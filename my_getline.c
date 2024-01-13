#include "shell.h"

/**
* my_getline - custom getline function
* Return: array of read strings on success.
*/

char *my_getline(void)
{
	ssize_t getline_num;

	char *buff = NULL;

	size_t buff_size = 0;


	getline_num = getline(&buff, &buff_size, stdin);

	if (getline_num == -1)
	{

		if (feof(stdin))
		{
			_putchar('\n');
			free(buff);
			exit(EXIT_SUCCESS);
		}
		else 
		{
			free(buff);
			perror("Getline Failed");
			exit(EXIT_FAILURE);
		}
	}

	return (buff);
}
