#include "main.h"

/**
 * remove_newline - Function to remove newline character from input
 * @str: input string
 *
 * Return: Always 0 successful
 */

void remove_newline(char *str)
{
	char *newline = strchr(str, '\n');

	if (newline != NULL)
	{
		*newline = '\0';
	}
}
