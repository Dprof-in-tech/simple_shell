#include "main.h"

/**
 * handle_path - Function to find the full path of commands
 * @command: input command
 * @arguments: Arguments to command
 *
 * Return: Always 0 success
 */

char *handle_path(char *command, char *arguments[])
{
	char *path = getenv("PATH");
	char *path_token = strsep(&path, ":");
	char *exe_path;
	bool found_in_current_dir = false;

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", command);
		exit(127);
	}
	while (path_token != NULL)
	{
		exe_path = malloc(strlen(path_token) + strlen(command) + 2);
		if (exe_path == NULL)
		{
			perror("malloc");
			free(command);
			return (NULL);
		}
		snprintf(exe_path, strlen(path_token)
			+ strlen(command) + 2, "%s/%s", path_token, command);

		if (access(exe_path, X_OK) == 0)
		{
			handle_fullshell(exe_path, arguments);
			free(exe_path);
			return (0);
		}
		free(exe_path);
		path_token = strsep(&path, ":");
		if (access(command, X_OK) == 0)
			found_in_current_dir = true;

	}
	if (!found_in_current_dir)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", command);
		exit(127);
	}
	return (0);
}


/**
 * handle_fullshell - Function to handle the full path of commands
 * @exe_path: Full path of user commands
 * @arguments: Arguments to the command
 *
 * Return: Always 0 successful
 */

void handle_fullshell(char *exe_path, char *arguments[])
{
	char **newargv;
	int arg_count = 0;
	int status, i;
	pid_t my_pid1;

	while (arguments[arg_count] != NULL)
		arg_count++;
	newargv = (char **)malloc((arg_count + 2) * sizeof(char *));
	if (newargv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	my_pid1 = fork();
	if (my_pid1 == 0)
	{
		newargv[0] = exe_path;
		for (i = 0; i < arg_count; i++)
		{
			newargv[i + 1] = arguments[i];
		}
		newargv[arg_count + 1] = NULL;
		if (execvp(exe_path, newargv) == -1)
		{
			perror(exe_path);
			free(newargv);
			exit(1);
		}
	}
	else if (my_pid1 < 0)
	{
		perror("fork");
		free(newargv);
	}
	else
	{
		waitpid(my_pid1, &status, 0);
		free(newargv);
	}
}
