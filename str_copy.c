#include "shell.h"
/**
 *str_copy - copy a string from src to dest
 *@dest: where to copy string to
 * @src: the string to copy
 * Return: dest
 */
char *str_copy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
