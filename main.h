#ifndef SHELL_HEADER_FILE
#define SHELL_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64
#define MAX_PATHS 64
#define MAX_PATH_LENGTH 1024
#define NUM_PATHS MAX_PATHS

char *get_cmd_path(char *cmd_name, char **paths);
extern char **environ;

void loop(void);
char *get_cmd_path(char *cmd_name, char **paths);
void execute_cmd(char **args);
int parse_cmd_line(char *line, char **args);
char *read_cmd_line(void);
void exit_builtin(char **args);
void env_builtin(char **args);
void handle_redirection(char **args);

#endif
