#include "shell.h"

/**
* get_env - get environment from shell.
* @env_var: environment variable to get.
* Return: sucess returns environment, otherwise NULL.
*/

char *get_env(char *env_var)
{
	char **_env;

	size_t len = 0;

	char *e_env;

	if (env_var == NULL)
	{
		return (NULL);
	}


	for (_env = environ; *_env != NULL; _env++)
	{
		e_env = *_env;

		len = _strlen(env_var);

		if (strn_cmp(e_env, env_var, len) == 0 && e_env[len] == '=')
		{
			return (&e_env[len + 1]);
		}
	}

	return (NULL);
}
