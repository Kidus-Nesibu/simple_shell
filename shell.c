#include "shell.h"

/**
* main - this is the main executing function
* Return: Always 0
*/
int main(void)
{
	char *cmd = NULL;
	size_t len = 0;

	while (1)
	{
	printf("#cisfun$ ");
	fflush(stdout);

	if (getline(&cmd, &len, stdin) == -1)
	{
		printf("\nExiting the shell.\n");
		break;
	}
	if (cmd[strlen(cmd) - 1] == '\n')
		cmd[strlen(cmd) - 1] = '\0';

	execute_command(cmd);
	}

	free(cmd);

	return (0);
}

/**
* execute_command - the function with the execute command
* @cmd: the command to be executed
* Return: void
*/
void execute_command(char *cmd)
{
	pid_t pid = fork();

	if (pid < 0)
	{
	perror("Fork failed");
		exit(EXIT_FAILURE);

	}
	else if (pid == 0)
	{
	char *argv[MAX_COMMAND_LENGTH];

	tokenize_command(cmd, argv);
	execve(argv[0], argv, NULL);
	perror("./shell");
	exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		wait(&status);
	}
}

/**
* tokenize_command - this func tokenizes the command
* @cmd: the command input
* @argv: the array of commands
* Return: void
*/
void tokenize_command(char *cmd, char *argv[])
{
	char *token;
	int i = 0;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");

	argv[i] = NULL;
	}
}

/**
* str_cmp - compares two strings
* @str1: input for string 1
* @str2: input for string 2
* Return: 0 if they are the same otherwise if not
*/
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
