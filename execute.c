#include "main.h"
/**
 * execute_cmd - execute commande
 * @args: argumment string
 * Return: Always 0.
 */
void execute_cmd(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		handle_redirection(args);
		execve(args[0], args, NULL);

		printf("Error executing command\n");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{

		printf("Error forking process\n");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
