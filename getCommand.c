#include "main.h"

/**
 * getPath - the path to the command
 * @command: the command
 * Return: 0
 */
char *getPath(char *command)
{
	char *path, *pathcpy, *token, *file;
	int com_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		pathcpy = _strdup(path);
		com_len = _strlen(command);
		token = strtok(pathcpy, ":");

		while (token)
		{
			dir_len = _strlen(token);
			file = malloc(com_len + dir_len + 2);
			_strcpy(file, token);
			_strcat(file, "/");
			_strcat(file, command);
			_strcat(file, "\0");

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
		else if (stat(command, &buffer) == -1)
			perror("./shell ");
		return (NULL);
	}
	return (NULL);
}
