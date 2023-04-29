#include"main.h"
/**
 * handle_redirection - check the code
 * @args: argumment string
 * Return: Always 0.
*/
void handle_redirection(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], "<") == 0)
		{
			int fd = open(args[i + 1], O_RDONLY);

			if (fd == -1)
			{
				printf("Error: could not open file %s for input.\n", args[i + 1]);
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			args[i] = NULL;
		}
		else if (strcmp(args[i], ">") == 0)
		{
			int fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

			if (fd == -1)
			{
				printf("Error: could not open file %s for output.\n", args[i + 1]);
				exit(1);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			args[i] = NULL;
		}
	}
}
