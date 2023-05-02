#include "main.h"
/**
 * parse_cmd_line - tokenizes the input line into individual arguments.
 * @line: line
 * @args: argumment vector
 * Return: a pointer to the line.
 */
char **parse_cmd_line(char *line, char *args)
{
	char *ptr = NULL;
	char **cmd = NULL;
	size_t i = 0;

	ptr = strtok(line, args);

	while (ptr)
	{
		cmd = realloc(cmd, ((i + 1) * sizeof(char *)));
		cmd[i] = strdup(ptr);
		ptr = strtok(NULL, args);
		++i;
	}
	cmd = realloc(cmd, ((i + 1) * sizeof(char *)));
	cmd[i] = NULL;
	return (cmd);
}
