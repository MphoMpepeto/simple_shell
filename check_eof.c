#include "shell.h"

/**
 * check_eof - check end of file
 * return: void
 */

void check_eof(char *buff)
{
	/*Check the condition of the end of file*/
	if (feof(stdin))
	{
		_putchar('\n');
		free(buff);
		exit(EXIT_SUCCESS);
	}
	else /*This indicates an error cause it's not end of file*/
	{
		free(buff);
		perror("Getline Failed");
		exit(EXIT_FAILURE);
	}
}
