#include "shell.h"

/**
*my_getline - this is my custom getline function
* Return: this function returns the array of read strings on success.
*/

char *my_getline(void)
{
	ssize_t getline_num;
	size_t buff_size = 0;

	char *buff = NULL;

	getline_num = getline(&buff, &buff_size, stdin);

	if (getline_num == -1)
	{
		check_eof(buff);
	}

	/*Control reads to this point indicate no errors encountered.*/

	return (buff);
}
