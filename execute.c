#include "main.h"
/**
 * execute_cmd - execute commande
 * @args: argumment string
 * Return: Always 0.
 */
void execute_cmd(char **args)
{
	pid_t pid = 0;
	int status = 0;

	pid = fork();
	if (pid == -1)
		perror("fork");

	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(args[0], args, NULL) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}
