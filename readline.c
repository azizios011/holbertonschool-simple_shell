#include"main.h"
/**
 * read_cmd_line - reads a line of input from stdin.
 *
 * Return: line.
*/
char *read_cmd_line(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t length = getline(&line, &size, stdin);

	if (length == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			printf("Error: could not read command.\n");
			exit(1);
		}
	}

	if (line[length - 1] == '\n')
	{
		line[length - 1] = '\0';
	}

	return (line);
}
