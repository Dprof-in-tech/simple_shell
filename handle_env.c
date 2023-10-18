#include "main.h"

/**
 * custom_get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
void custom_get_environ(info_t *info)
{
	char **env;

	for (env = info->environ; *env != NULL; env++)
		printf("%s\n", *env);
}
