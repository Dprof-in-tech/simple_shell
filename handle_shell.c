#include "main.h"

/**
 * handle_shell -  Function to handle basic shell operations
 * @command: User input
 * @arguments: Command arguments
 *
 * Return: Always successful 0
 */

void handle_shell(char *command, char *arguments[])
{
	int arg_count = 0;
	char **newargv = NULL;
	pid_t my_pid;
	int status, i;

	my_pid = fork();
	if (my_pid == 0)
	{
		if (arguments == NULL)
			execlp(command, command, (char *)NULL);
		else
		{
			while (arguments[arg_count] != NULL)
				arg_count++;
			newargv = (char **)malloc((arg_count + 2) * sizeof(char *));
			if (newargv == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			newargv[0] = command;
			for (i = 0; i < arg_count; i++)
				newargv[i + 1] = arguments[i];
			newargv[arg_count + 1] = NULL;
			if (execvp(command, newargv) == -1)
			{
				perror(command);
				free(newargv);
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (my_pid < 0)
		perror("fork");
	else
	{
		waitpid(my_pid, &status, 0);
		free(newargv);
	}
}
