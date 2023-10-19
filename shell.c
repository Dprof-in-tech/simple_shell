#include "main.h"

/**
 * allocate_memory - Function to allocate memory to store input
 * @input_line: user input
 *
 * Return: ALways 0 success
 */

void allocate_memory(char **input_line)
{
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];

	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
	if (bytes_read == 0)
	{
		*input_line = NULL;
	}
	else if (bytes_read == -1)
	{
		perror("read");
		*input_line = NULL;
	}
	else if (bytes_read > 0)
	{
		*input_line = (char *)malloc(bytes_read + 1);
		if (*input_line == NULL)
		{
			perror("malloc");
			return;
		}

		memcpy(*input_line, buffer, bytes_read);
		(*input_line)[bytes_read] = '\0';
	}
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
	char *token, *input_line = NULL;
	char *command = NULL, *arguments[MAX_ARGS];
	int arg_count = 0, error_flag = 0;
	info_t info;

	info.environ = environ;
	while (1)
	{
		check();
		allocate_memory(&input_line);
		if (input_line == NULL)
			break;
		arg_count = 0;
		command = tokenizer(&input_line);
		if (command == NULL)
			continue;
		while (!error_flag && (token = tokenizer(&input_line)) != NULL)
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
		if (!isatty(STDIN_FILENO))
		{
			break;
		}
		free_memory(input_line);
	}
	return (0);
}
