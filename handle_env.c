#include "main.h"

/**
 * handle_env - Function to handle environment command
 * @command: main command
 *
 * Return: Always 0 success
 */

int handle_env(char *command)
{
	char **env;

	if (command != NULL)
	{
		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}
	}
	return (0);
}
