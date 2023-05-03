#include "main.h"
/**
 * free_line - free one line
 * @lines : block commande
 *
 */
void free_line(char **lines)
{
	int i;

	for (i = 0; lines[i]; i++)
	{
		free(lines[i]);
		lines[i] = NULL;
	}
	free(lines);
	lines = NULL;
}
