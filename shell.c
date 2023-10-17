#include "main.h"

/**
 * allocate_memory - Function to allocate memory to store input
 *
 * Return: ALways 0 success
 */

char *allocate_memory(void)
{
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	char *input_line = NULL;

	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
	if (bytes_read == 0)
	{
		return (NULL);
	}
	else if (bytes_read == -1)
	{
		perror("read");
		return (NULL);
	}

	input_line = (char *)malloc(bytes_read + 1);
	if (input_line == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	memcpy(input_line, buffer, bytes_read);
	input_line[bytes_read] = '\0';

	return (input_line);
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
	char *input_line = NULL, *token;
	char *command = NULL, *arguments[MAX_ARGS];
	int arg_count = 0;

	while (1)
	{
		check();
		input_line = allocate_memory();
		if (input_line == NULL)
		{
			break;
		}
		arg_count = 0;
		command = tokenizer(&input_line);
		if (command == NULL)
			continue;
		while ((token = tokenizer(&input_line)) != NULL)
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
			handle_env(command);
		else if (is_file(command))
			handle_shell(command, arguments);
		else
			handle_path(command, arguments);
		free(input_line);
	}
	return (0);
}
