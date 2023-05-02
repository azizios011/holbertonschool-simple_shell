#ifndef SHELL_HEADER_FILE
#define SHELL_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
#endif
