#include "shell.h"

/**
 * she_prints - a custom printf function with min functionality.
 * @formt: a pointer to a format specifier
 * Return: amount of chars printed.
 */

int she_prints(const char *formt, ...);

int she_prints(const char *formt, ...)
{
	int index;

	int _chars = 0;

	va_list fs_args;

	va_start(fs_args, formt);

	if (formt == NULL)
	{
		return (-1);
	}

	for (index = 0; formt[index] != '\0'; index++)
	{
		if (formt[index] == '%')
		{
			index += 1;

			if (formt[index] == '%')
			{
				_putchar('%');
				_chars += 1;
			}
			else if (formt[index] == 'c')
			{
				char char_num = va_arg(fs_args, int);

				if (char_num)
				{
					_putchar(char_num);
					_chars += 1;
				}
				else
				{
					exit(-1);
				}
			}
			else if (formt[index] == 's')
			{
				char *strng_value = va_arg(fs_args, char *);

				int strng_index = 0;

				int strng_len = 0;

				for (strng_index = 0; strng_value[strng_index] != '\0'; strng_index++)
				{
					_putchar(strng_value[strng_index]);
				}

				while (*strng_value != '\0')
				{
					strng_len += 1;

					strng_value += 1;
				}

				_chars += strng_len;
			}
		}
		else
		{
			_putchar(formt[index]);
			_chars += 1;
		}
	}

	va_end(fs_args);

	return (_chars);
}

