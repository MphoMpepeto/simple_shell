#include "shell.h"
/**
 * is_interact - check if prompt is interactive
 * Return: bool
 */
bool is_interact(void)
{
	return (isatty(STDIN_FILENO));
}
