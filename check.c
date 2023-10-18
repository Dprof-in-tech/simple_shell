#include "main.h"

/**
 * check - Function to check if its interactive  mode
 *
 * Return: Always 0 success
 */

void check(void)
{
	char hostn[1204] = "";
	char currentDirectory[1024] = "";

	if (isatty(STDIN_FILENO))
	{
		gethostname(hostn, sizeof(hostn));
		printf("%s@%s:~%s$ ", getenv("LOGNAME"), hostn,
				getcwd(currentDirectory, 1024));
		fflush(stdout);
	}
}
