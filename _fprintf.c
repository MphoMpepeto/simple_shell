#include "shell.h"

/**
* _err_printf - this function that handles error output.
* @stream: file stream / file descriptor.
* @format: format specifer arguments.
*
* Return: total length of characters printed.
*/

int _err_printf(FILE *stream, const char *format, ...);

int _err_printf(FILE *stream, const char *format, ...)
{
	int x;

	int printed_chars = 0;

	va_list specifier_args;

	(void)stream;

	va_start(specifier_args, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			x += 1; 

			if (format[i] == '%')
			{
				error_printer('%');
			}
			else if (format[i] == 'c')
			{
				char c_val = va_arg(specifier_args, int);

				if (c_val)
				{
					error_printer(c_val);
					printed_chars += 1;
				}

			}
			else if (format[i] == 's')
			{
				char *str_val = va_arg(specifier_args, char *);

				int str_idx = 0;

				int str_len = 0;

				for (str_idx = 0; str_val[str_idx] != '\0'; str_idx++)
				{
					error_printer(str_val[str_idx]);
				}

				while (*str_val != '\0')
				{
					str_len += 1;

					str_val += 1;
				}

				printed_chars += str_len;
			}
			else if (format[i] == 'd')
			{
				int num_len = 0;

				int dec_val = va_arg(specifier_args, int);

				if (!dec_val)
				{
					return (-1);
				}

				num_len = num_length(dec_val);

				print_integer(dec_val);
				printed_chars += num_len;
			}
		}
		else
		{
			error_printer(format[i]);
			printed_chars += 1;
		}
	}

	va_end(specifier_args);

	return (printed_chars);

}
