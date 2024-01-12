#include "shell.h"


/**
* _putchar - prints character to the standard output.
* @ch: character to be printed.
* Return: character.
*/
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
* strn_cmp - comares two strings
* @strA: first strng to be comapred.
* @strB: second sring to be compared.
* @val: byte to be comapared.
* Return: 0 on success.
*/

int strn_cmp(char *strA, char *strB, int val)
{
	int cmp = 0;

	int idx = 0;

	while ((*strA != '\0' || *strB != '\0') && idx < val)
	{
		if (*strA != *strB)
		{
			cmp += 1;
		}

		strA += 1;

		strB += 1;

		idx += 1;
	}

	if (cmp != 0)
	{
		return (-1);
	}

	return (cmp);
}
