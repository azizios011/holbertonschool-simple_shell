#include"main.h"
/**
 * split_line - tokenizes the input line into individual arguments.
 * @line: input line
 * Return: number of arguments
 */
char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[position] = NULL;
	return (tokens);
}
