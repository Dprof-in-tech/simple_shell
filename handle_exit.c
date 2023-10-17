#include "main.h"

/**
 * is_numeric - Function to check if argument is a number
 * @str: argument passed
 *
 * Return: Always 0 success
 */

int is_numeric(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * handle_exit - Function to handle exit and env command
 * @command: User command
 * @arguments: argument passed
 *
 * Return: Always successful 0
 */

void handle_exit(char *command, char *arguments[])
{
	int exit_code = 0;

	if (command != NULL && arguments[0] != NULL)
	{
		if (is_numeric(arguments[0]))
		{
			exit_code = atoi(arguments[0]);
			free(command);
			exit(exit_code);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: Illegal number: %s\n", command, *arguments);
			fflush(stderr);
			free(command);
			exit(2);
		}
	}

	free(command);
	exit(exit_code);
}
