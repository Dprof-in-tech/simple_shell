#include "main.h"

/**
 * handle_env - Function to handle environment command
 * @command: main command
 *
 * Return: Always 0 success
 */

void handle_env(char *command)
{
	char **env, **env_copy = NULL;
	int count = 0, i;

	if (command != NULL)
	{
		for (env = environ; *env != NULL; env++)
		{
			count++;
		}

		env_copy = (char **)malloc((count + 1) * sizeof(char *));
		if (env_copy == NULL)
		{
			perror("malloc");
			return;
		}

		for (i = 0; i < count; i++)
			env_copy[i] = environ[i];
		env_copy[count] = NULL;

		qsort(env_copy, count, sizeof(char *), cmpstr);

		for (i = 0; i < count; i++)
			printf("%s\n", env_copy[i]);

		free(env_copy);
	}
}

/**
 * cmpstr - Function to compare strings
 * @b: input string
 * @c: input_string
 *
 * Return: The compared string
 */

int cmpstr(const void *b, const void *c)
{
	return (strcmp(*(const char **)b, *(const char **)c));
}
