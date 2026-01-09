#include "shell.h"

/**
 * parse_line - Splits a command line into arguments
 * @line: Input line
 *
 * Return: NULL-terminated array of arguments
 */
char **parse_line(char *line)
{
	char **argv;
	char *token;
	int i;

	argv = malloc(sizeof(char *) * MAX_ARGS);
	if (argv == NULL)
		return (NULL);

	token = strtok(line, " ");
	i = 0;

	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	argv[i] = NULL;
	return (argv);
}
