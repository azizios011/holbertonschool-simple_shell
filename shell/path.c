#include "main.h"
/**
 * get_cmd_path - get the full path of a command
 * @cmd_name: name of the command
 * @paths: array of directories in the PATH environment variable
 *
 * Return: On success, returns a pointer to a string containing
 *  the full path of the command. On failure, returns NULL.
 */
char *get_cmd_path(char *cmd_name, char **paths)
{
	char *path, *dir, *full_path;
	struct stat st;
	int i;

	for (i = 0; paths[i] != NULL; i++)
	{
		dir = paths[i];
		path = malloc(sizeof(char) * (strlen(dir) + strlen(cmd_name) + 2));
		if (path == NULL)
			return (NULL);
		sprintf(path, "%s/%s", dir, cmd_name);
		if (stat(path, &st) == 0)
		{
			full_path = strdup(path);
			free(path);
			return (full_path);
		}
		free(path);
	}
	return (NULL);
}
