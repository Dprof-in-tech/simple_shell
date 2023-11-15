#include "main.h"

/**
 * process_command - Function to allocate memory to store input
 * @command: user input
 * @arguments:  command arguments
 * @info: exit info
 *
 * Return: ALways 0 success
 */

void process_command(char *command, char *arguments[], info_t *info)
{
	if (strcmp(command, "exit") == 0)
		handle_exit(command, arguments);
	else if (strcmp(command, "env") == 0)
		custom_get_environ(info);
	else if (is_file(command))
		handle_shell(command, arguments);
	else if (strcmp(command, "cd") == 0)
		changeDirectory(arguments);
	else
		handle_path(command, arguments);
}

/**
 * free_memory - Function to free memory
 * @arguments: memory to clean
 *
 * Return: Always 0 successful
 */

void free_memory(char *arguments[])
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		free(arguments[i]);
}

/**
 * is_file - Function to check if command exists
 * @path: command
 *
 * Return: Always 0 success
 */

int is_file(const char *path)
{
	struct stat file_info;

	return (stat(path, &file_info) == 0 && S_ISREG(file_info.st_mode));
}

/**
 * main - Function that emulates simple shell
 *
 * Return: Always 0 success
 */

int main(void)
{
	char *token, *input_line = NULL, *input_copy = NULL;
	size_t len = 0;
	char *command = NULL, *arguments[MAX_ARGS];
	int arg_count = 0, error_flag = 0;
	info_t info;

	info.environ = environ;
	while (1)
	{
		check();
		if (getline(&input_line, &len, stdin) == -1)
			break;
		arg_count = 0;
		input_copy = strdup(input_line);
		command = tokenizer(&input_copy);
		if (command == NULL)
			continue;
		while (!error_flag && (token = tokenizer(&input_copy)) != NULL)
		{
			if (is_file(token))
				handle_shell(token, NULL);
			else
				arguments[arg_count++] = token;
		}
		arguments[arg_count] = NULL;
		process_command(command, arguments, &info);

		free(input_copy);
		free(input_line);
	}
	free(input_copy);
	free(command);
	return (0);
}
