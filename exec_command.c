#include "shell.h"
/**
 * yenza_command - Executes user input command
 * @nipa_input: command and options entered by user
 * Return: nothing
 * Description: Executes command entered by user
 */
void yenza_command(char *nipa_input)
{
	pid_t cp_id = fork();
	int pokemon_count = 0;
	char *pokemon, *delimetr = " \n", **array_of_pokemons;
	char *copy_nipa = malloc(sizeof(char) * (strlen(nipa_input) + 1));

	array_of_pokemons = malloc(sizeof(char *) * (pokemon_count + 1));
	check_malloc(&copy_nipa);
	str_copy(copy_nipa, nipa_input);
	pokemon = strtok(nipa_input, delimetr);

	while (pokemon != NULL)
	{
		pokemon_count++;
		pokemon = strtok(NULL, delimetr);
	}
	if (cp_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	check_malloc(array_of_pokemons);
	if (cp_id == 0)
	{
		ye_commd(copy_nipa, array_of_pokemons, pokemon, delimetr);
	}
	else
	{
		wait(NULL);
	}
	free(array_of_pokemons);
	free(copy_nipa);
}
