#include "shell.h"

/**
* non_interactive_reader - Read input from the user in non interactive mode.
* Return: On succes, it returns pointer to array of characters.
*/
char *non_interactive_reader(void);

char *non_interactive_reader(void)
{
	ssize_t value_read;

	char *buff, *loc_ptr;

	int i = 0, max_size = 1024;

	char ch;

	buff = malloc(max_size * sizeof(char));

	if (buff == NULL)
	{
		print_error();
	}

	value_read  = read(STDIN_FILENO, &ch, 1);

	while ((value_read) > 0)
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
				print_error();
				free(buff);
			}

			buff = loc_ptr;
		}
	}
	
	switch (value_read) {
		case -1:
			print_error();
			free(buff);
			break;
		case 0:
			free(buff);
			exit(1);
			break;
		default:
			break;
	}

	buff[i] = '\0';

	return (buff);
}
