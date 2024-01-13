#include "shell.h"

/**
* non_interactive_reader - Read input from user in non-interactive mode
* Return: On succes, it returns the pointer to the array of characters.
*/
char *non_interactive_reader(void);

char *non_interactive_reader(void)
{
	ssize_t value_read;

	char *buff;

	char *loc_ptr;

	int i = 0;

	int max_size = 1024;

	char ch;

	buff = malloc(max_size * sizeof(char));

	if (buff == NULL)
	{
		perror("Failed to allocate memory");

		exit(1);
	}

	while ((value_read = read(STDIN_FILENO, &ch, 1)) > 0)
	{
		if (ch == EOF || ch == '\n')
		{
			break;
		}

		buff[i++] = ch;


		if (i >= (max_size - 1))
		{
			max_size += 1024;

			loc_ptr = realloc(buff, max_size);

			if (loc_ptr == NULL)
			{
				perror("Reallocation of memory failed");

				free(buff);

				exit(1);
			}

			buff = loc_ptr;
		}
	}


	if (value_read == -1)
	{
		perror("Read failed");
		free(buff);
		exit(1);
	}


	if (value_read == 0)
	{
		free(buff);

		exit(1);
	}

	buff[i] = '\0';

	return (buff);
}
