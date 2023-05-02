#include"main.h"
/**
 * read_line - reads a line of input from stdin.
 *
 * Return: line.
*/
char *read_line(void)
{
	int bufsize = BUFFER_SIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}

		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			buffer = realloc(buffer, sizeof(char) * bufsize);

			if (!buffer)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
