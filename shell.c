#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void environment(void);
void execute_command(char *cmd);
void tokenize_command(char *cmd, char *argv[]);
int str_cmp(const char *str1, const char *str2);

int main() {
	char *cmd = NULL;
	size_t len = 0;

	while (1) {
	printf("$ ");
	fflush(stdout);

	if (getline(&cmd, &len, stdin) == -1) {
		printf("\nExiting the shell.\n");
		break;
	}
	if (cmd[strlen(cmd) - 1] == '\n') {
		cmd[strlen(cmd) - 1] = '\0';
	}
	if (str_cmp(cmd, "env") == 0)
	{
		environment();
	}
	if (str_cmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	execute_command(cmd);
	}

	free(cmd);

	return 0;
}

void execute_command(char *cmd) {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
	char *argv[MAX_COMMAND_LENGTH];
	tokenize_command(cmd, argv);
	execve(argv[0], argv, NULL);
	perror("Error");
	exit(EXIT_FAILURE);
	} else {
		int status;
		wait(&status);
	}
}

void tokenize_command(char *cmd, char *argv[]) {
	char *token;
	int i = 0;

	token = strtok(cmd, " ");
	while (token != NULL) {
		argv[i++] = token;
		token = strtok(NULL, " ");

	argv[i] = NULL;
	}
}
void environment()
{
	extern char** environ;
	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

int str_cmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
