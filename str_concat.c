#include "shell.h"
/**
  * str_concat - concatenates two string
  * @dest: the string to print representing destination
  * @src: the string to be added
  * Return: destination string on success
  */
char *str_concat(char *dest, char *src)
{
	int len = 0, i = 0;

	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
