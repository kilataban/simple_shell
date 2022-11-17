#include "main.h"

/**
 * path - path to the executable
 * execu - path to the executable
 * @command: the command
 * Return: 0
 */
char *execu(char *command)
{
	char *path, *pathcpy, *token, *file;
	int com_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		pathcpy = strdup(path);
		com_len = strlen(command);

		token = strtok(pathcpy, ":");
		while (token)
		{
			dir_len = strlen(token);
			file = malloc(com_len + dir_len + 2);
			strcpy(file, token);
			strcat(file, "/");
			strcat(file, command);
			strcat(file, "\0");

			if (stat(file, &buffer) == 0)
			{
				free(pathcpy);
				return (file);
			}
			else
			{
				free(file);
				token = strtok(NULL, ":");
			}
		}
		free(pathcpy);
		if (stat(command, &buffer) == 0)
			return (command);
		else
		{
			perror("./shell");
			return (NULL);
		}
	}
	return (NULL);
}
