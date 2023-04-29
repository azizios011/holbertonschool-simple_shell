#include"main.h"
/**
 * loop - the main function
 *
 * Return: Always 0.
*/
void loop(void)
{
	char *line;
	char *args[MAX_ARGS];
	int num_args;
	char *cmd_path;

	char *paths[] = {"/bin", "/usr/bin", NULL};

	while (1)
	{
		printf("($) ");
		line = read_cmd_line();
		num_args = parse_cmd_line(line, args);
		if (num_args > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
			exit_builtin(args);
			}
			else if (strcmp(args[0], "env") == 0)
			{
			env_builtin(args);
			}
			else
			{
				cmd_path = get_cmd_path(args[0], paths);
				if (cmd_path != NULL)
				{
				execute_cmd(args);
				free(cmd_path);
				}
				else
				{
					printf("Command not found\n");
			}
			}
		}
		free(line);
	}
}
