#include "main.h"

/**
 * changeDirectory - Function to change directory
 * @arguments: input path to go to
 *
 * Return: Always 0 successfull
 */

void changeDirectory(char *arguments[])
{
	int i;
	const char *path = NULL, *line;
	char *currentDir = getcwd(NULL, 0), *previousDir;

	for (i = 0; arguments[i] != NULL; i++)
	{
		line = arguments[i];
		if (line == NULL)
			path = getenv("HOME");
		else if (strcmp(line, "-") == 0)
			path = getenv("OLDPWD");
		else
			path = line;

		if (path != NULL)
		{
			previousDir = currentDir;
			if (chdir(path) != 0)
			{
				perror("cd");
				free(previousDir);
				exit(EXIT_FAILURE);
			}
			setenv("OLDPWD", previousDir, 1);
			free(previousDir);
			currentDir = getcwd(NULL, 0);
			if (currentDir == NULL)
			{
				perror("getcwd");
				exit(EXIT_FAILURE);
			}
			if (setenv("PWD", currentDir, 1) != 0)
				perror("setenv");
		}
	}
	free(currentDir);
}
