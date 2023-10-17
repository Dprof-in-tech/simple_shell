#include "main.h"

void check(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("($) ");
		fflush(stdout);
	}
}
