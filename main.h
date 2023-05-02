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

extern char **environ;

void loop(void);
void get_cmd_path(char **paths);
void execute_cmd(char **args);
char **parse_cmd_line(char *line, char *args);
char *read_cmd_line(void);
void print_env(void);
void free_line(char **lines);
void exit_builtin(char **args);
void env_builtin(char **args);
void cd_builtin(char **args);
#endif
