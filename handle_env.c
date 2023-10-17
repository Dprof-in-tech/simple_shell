#include "main.h"

/**
 * handle_env - Function to handle environment command
 * @command: main command
 *
 * Return: Always 0 success
 */

int handle_env(char *command)
{
	char **env = environ;

	if (command != NULL)
	{
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	return (0);
}
