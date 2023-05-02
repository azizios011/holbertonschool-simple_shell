#include"main.h"
/**
 * execute - executes a command with optional I/O redirection
 * @args: argument vector
 * Return: Always 0.
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	pid = fork();

	if (pid == 0)
	{
		char *envp[] = { NULL };

		if (execve(args[0], args, envp) == -1)
		{
			perror("hsh");
		}

		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
