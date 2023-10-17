#include "main.h"

int handle_env(char *command)
{
	extern char **environ;
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
