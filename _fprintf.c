#include "shell.h"

/**
* _err_printf - this function that handles error output.
* @strm: file stream or file descriptor.
* @formt: format specifier.
*
* Return: total length of characters printed.
*/

int _err_printf(FILE *strm, const char *formt, ...);

int _err_printf(FILE *strm, const char *formt, ...)
{
	int x;

	int _chars = 0;

	va_list spf_args;

	(void)strm;

	va_start(spf_args, formt);

	for (x = 0; formt[x] != '\0'; x++)
	{
		if (formt[x] == '%')
		{
			x += 1; 

			if (formt[x] == '%')
			{
				error_printer('%');
			}
			else if (formt[x] == 'c')
			{
				char c_char = va_arg(spf_args, int);

				if (c_char)
				{
					error_printer(c_char);
					_chars += 1;
				}

			}
			else if (formt[x] == 's')
			{
				char *strng_value = va_arg(spf_args, char *);

				int strng_index = 0;

				int strng_len = 0;

				for (strng_index = 0; strng_value[strng_index] != '\0'; strng_index++)
				{
					error_printer(strng_value[strng_index]);
				}

				while (*strng_value != '\0')
				{
					strng_len += 1;

					strng_value += 1;
				}

				_chars += strng_len;
			}
			else if (formt[x] == 'd')
			{
				int num_len = 0;

				int decimal_val = va_arg(spf_args, int);

				if (!decimal_val)
				{
					return (-1);
				}

				num_len = num_length(decimal_val);

				output_int(decimal_val);
				_chars += num_len;
			}
		}
		else
		{
			error_printer(formt[x]);
			_chars += 1;
		}
	}

	va_end(spf_args);

	return (_chars);

}
