#include"main.h"
/**
 * parse_cmd_line - parsing a line
 * @line: 
 * Return: EXIT_SUCCESS
*/
char **parse_cmd_line(char *cmd_line)
{
    char *token;
    char **args = malloc(sizeof(char*) * MAX_ARGS);
    int i = 0;

    token = strtok(cmd_line, " \t\n");
    while (token != NULL)
    {
        args[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    return (args);
}
