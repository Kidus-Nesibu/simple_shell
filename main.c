#include "shell.h"

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
		{
			cmd[strlen(cmd) - 1] = '\0';
		}

		execute_command(cmd);
	}

	free(cmd);

	return (0);
}

/**
 * execute_command - Execute the specified command
 * @cmd: commands to be executed
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
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		wait(&status);
	}
}

/**
 * tokenize_command - Tokenize the command string into an array of strings
 * @cmd: command strings to be tokenized
 * @argv: array that store and tokenize them
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
	}

	argv[i] = NULL;
}

