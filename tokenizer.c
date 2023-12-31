#include "main.h"

/**
 * tokenizer - Function to tokenize input
 * @input_line: input string to be tokenized
 *
 * Return: Always 0 successful
 */

char *tokenizer(char **input_line)
{
	char *token;
	char *delimiters = "  \t\n";

	while ((token = strsep(input_line, delimiters)) != NULL)
	{
		if (strlen(token) > 0)
			return (token);

		if (*input_line == NULL || **input_line == '\0')
			return (NULL);
	}

	return (NULL);
}
