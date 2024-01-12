#include "shell.h"

/**
* error_printer - Print error to stdoutput
* @ch: character to be printed to stderr
* Return: character.
*/

int error_printer(char ch)
{
	return (write(STDERR_FILENO, &ch, 1));
}

/**
* output_int - print interger.
* @num: number to be printed.
* Return: void
*/

void output_int(int num)
{
	int idx;

	int index_bf = 0;

	char buff[12];

	if (num < 0)
	{
		error_printer('-');
		num = -(num);
	}

	if (num == 0)
	{
		error_printer('0');
		return;
	}

	while (num > 0)
	{
		buff[index_bf] = '0' + (num % 10);

		num /= 10;

		index_bf += 1;
	}

	for (idx = index_bf - 1; idx >= 0; idx--)
	{
		error_printer(buff[idx]);
	}
}


/**
* num_length - count length of integer.
* @num: integer length to count.
* Return: lenght of integer.
*/

int num_length(int num)
{
	int real_length = 0;

	if (num == 0)
	{
		return (1);
	}

	if (num < 0)
	{
		real_length += 1;
		num = -(num);
	}

	do {
		real_length += 1;
		num /= 10;
	} while (num > 0);

	return (real_length);
}
