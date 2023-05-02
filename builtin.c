#include "main.h"
/**
 * exit_builtin - check the code
 * @args: argumment string
 * Return: Always 0.
 */
void exit_builtin(char **args)
{
	if (args[1] != NULL)
	{
		printf("Error: too many arguments for exit.\n");
	}
	else
	{
		exit(0);
	}
}

/**
 * env_builtin - check the code
 * @args: argumment string
 * Return: Always 0.
 */
void env_builtin(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		char *value = getenv(args[i]);

		if (value != NULL)
		{
			printf("%s=%s\n", args[i], value);
		}
	}
}
/**
 * cd_builtin - change directory
 * @args: argument string
 *
 * Return: Always 0.
 *
int cd_builtin(char **args)
{
	char *new_dir;

	if (args[1] == NULL)
	{
		new_dir = getenv("/");
		if (new_dir == NULL)
		{
			perror("cd");
			return 1;
		}
	}
	else
	{
		new_dir = args[1];
	}

	if (chdir(new_dir) != 0)
	{
		perror("cd");
		return 1;
	}

	return 0;
}*/
void cd_builtin(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "shell: cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell: cd");
		}
	}
}
