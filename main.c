#include "shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **envp)
{
	char *line;
	size_t len;
	ssize_t read;
	int interactive;

	(void)argc;
	(void)argv;

	line = NULL;
	len = 0;
	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			prompt();

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (*line == '\0')
			continue;

		execute_command(line, envp);
	}
}
