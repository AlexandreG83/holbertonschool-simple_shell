#include "shell.h"

/**
 * prompt - Displays the shell prompt
 *
 * Return: Nothing
 */
void prompt(void)
{
	write(STDOUT_FILENO, ":) ", 3);
}

/**
 * execute_command - Executes a command with arguments and PATH handling
 * @line: Input command line
 * @envp: Environment variables
 *
 * Return: Nothing
 */
void execute_command(char *line, char **envp)
{
	pid_t pid;
	char **argv;
	char *cmd_path;

	argv = parse_line(line);
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}

	cmd_path = get_path(argv[0], envp);
	if (cmd_path == NULL)
	{
		perror("./shell");
		free(argv);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		free(argv);
		return;
	}

	if (pid == 0)
	{
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}

	free(cmd_path);
	free(argv);
}
