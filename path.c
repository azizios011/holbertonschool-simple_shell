#include "main.h"
/**
 * get_cmd_path - get the full path of a command
 * @cmd_name: name of the command
 * @paths: array of directories in the PATH environment variable
 *
 */
void get_cmd_path(char **paths)
{
	int i;
	char *path = strdup(getenv("PATH"));
	char *bin = NULL;
	char **path_split = NULL;

	if (paths[0][0] != '/' && strncmp(paths[0], "./", 2) != 0)
	{

		path_split = parse_cmd_line(path, ":");
		free(path);
		path = NULL;

		for (i = 0; path_split[i]; i++)
		{
			bin = calloc(sizeof(char),
						 (strlen(path_split[i]) + 1 + strlen(paths[0]) + 1));
			if (bin == NULL)
				break;
			strcat(bin, path_split[i]);
			strcat(bin, "/");
			strcat(bin, paths[0]);
			if (access(bin, F_OK) == 0)
				break;

			free(bin);
			bin = NULL;
		}
		free_line(path_split);
		free(paths[0]);
		paths[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
}
