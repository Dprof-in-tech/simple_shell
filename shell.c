#include "main.h"

/**
 * allocate_memory - Function to allocate memory to store input
 * @input_line: user input
 *
 * Return: ALways 0 success
 */

void allocate_memory(char **input_line)
{
	printf("%s\n", *input_line);
}

/**
 * free_memory - Function to free memory
 * @input_line: memory to free
 *
 * Return: Always 0 successful
 */

void free_memory(char *input_line)
{
	if (input_line != NULL)
		free(input_line);
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
		if (strcmp(command, "exit") == 0)
			handle_exit(command, arguments);
		else if (strcmp(command, "env") == 0)
			custom_get_environ(&info);
		else if (is_file(command))
			handle_shell(command, arguments);
		else
			handle_path(command, arguments);

		free(input_copy);
		free(input_line);
	}
	free_memory(input_copy);
	free(command);
	return (0);
}
