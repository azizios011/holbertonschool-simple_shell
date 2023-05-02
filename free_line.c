#include "main.h"
/**
 * free
 *
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
