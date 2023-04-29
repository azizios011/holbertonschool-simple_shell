#include"main.h"
/**
 * parse_cmd_line - tokenizes the input line into individual arguments.
 * @line: line
 * @args: argumment vector
 * Return: a pointer to the line.
*/
int parse_cmd_line(char *line, char **args)
{
	int num_args = 0;
	char *token = strtok(line, " \t\n");

	while (token != NULL)
	{
		args[num_args++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[num_args] = NULL;
	return (num_args);
}
