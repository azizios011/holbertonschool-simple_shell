#include "main.h"
/**
 * loop - the main function
 *
 * Return: Always 0.
 */
void loop(void)
{
	char *line;
	char **cmd_path;
	struct stat status;

	while (1)
	{
		printf("($) ");
		line = read_cmd_line();
		cmd_path = parse_cmd_line(line, " \t\r\n");

		if (strcmp(cmd_path[0], "exit") == 0)
		{
			free_line(cmd_path);
			exit(0);
		}
		if (strcmp(cmd_path[0], "cd") == 0)
		{
			cd_builtin(cmd_path);
			free_line(cmd_path);
			continue;
		}
		else if (strcmp(cmd_path[0], "env") == 0)
		{
			free_line(cmd_path);
			print_env();
			continue;
		}
		if (stat(cmd_path[0], &status) != 0)
			get_cmd_path(cmd_path);
		if (cmd_path[0] == NULL)
			printf("Command not found\n");
		else
			execute_cmd(cmd_path);
		free_line(cmd_path);
	}
	free(line);
}
