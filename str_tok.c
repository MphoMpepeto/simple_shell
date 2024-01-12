#include "shell.h"

/**
* str_tok - this is a function that tokenizes a string
* @strng: string to be tokenized.
* @delimeter: criteria for splitting token
* Return: tokenized string on success, NULL otherwise.
*/

char *str_tok(char *strng, const char *delimeter);

char *str_tok(char *strng, const char *delimeter)
{
	static char *nxt_pokemon;

	char *n_pokemon;

	if (strng != NULL)
	{
		nxt_pokemon = strng;
	}

	if (nxt_pokemon == NULL || *nxt_pokemon == '\0')
	{
		return (NULL);
	}

	while (*nxt_pokemon != '\0' && strchr(delimeter, *nxt_pokemon) != NULL)
	{
		nxt_pokemon++;
	}


	if (*nxt_pokemon == '\0')
	{
		return (NULL);
	}

	n_pokemon = nxt_pokemon;

	while (*nxt_pokemon != '\0' && strchr(delimeter, *nxt_pokemon) == NULL)
	{
		nxt_pokemon += 1;
	}

	if (*nxt_pokemon != '\0')
	{
		*nxt_pokemon = '\0';

		nxt_pokemon += 1;
	}

	return (n_pokemon);
}
