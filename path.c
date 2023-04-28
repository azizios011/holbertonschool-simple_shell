#include"main.h"
/**
 * 
*/
char *get_cmd_path(char *cmd, char *env_path)
{
    char *path = strtok(env_path, ":");
    char cmd_path[256];

    while (path != NULL) {
        snprintf(cmd_path, sizeof(cmd_path), "%s/%s", path, cmd);

        if (access(cmd_path, X_OK) == 0)
        {
            return (strdup(cmd_path));
        }

        path = strtok(NULL, ":");
    }

    return (NULL);
}
