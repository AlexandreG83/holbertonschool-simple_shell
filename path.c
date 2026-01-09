#include "shell.h"

/**
 * get_path - Finds the full path of a command
 * @command: Command name
 * @envp: Environment variables
 *
 * Return: Full path if found, NULL otherwise
 */
char *get_path(char *command, char **envp)
{
	char *path_env;
	char *path;
	char *dir;
	char *full_path;
	int i;

	if (access(command, X_OK) == 0)
		return (strdup(command));

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break;
		}
	}

	if (envp[i] == NULL)
		return (NULL);

	path = strdup(path_env);
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
