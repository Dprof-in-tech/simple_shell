#include "main.h"

/**
 * check - Function to check if its interactive  mode
 *
 * Return: Always 0 success
 */

void check(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("($) ");
		fflush(stdout);
	}
}
