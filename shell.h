#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void environment(void);
void tokenize_command(char *cmd, char *argv[]);
int str_cmp(const char *str1, const char *str2);
void execute_command(char *cmd);

#endif
