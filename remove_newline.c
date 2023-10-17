#include "main.h"

void remove_newline(char *str)
{
	char *newline = strchr(str, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
}
