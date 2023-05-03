#include <string.h>
#include "main.h"
/**
 * print_env - function that print the cuurent environment
 */
void print_env(void)
{
	size_t t;
	int len;

	for (t = 0; environ[t] != NULL; t++)
	{
		len = strlen(environ[t]);
		write(1, environ[t], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
