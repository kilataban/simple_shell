#include "main.h"

/**
 * main - entry point
 * @ac: the count
 * @av: the vector
 * Return: 0
 */

int main(__attribute__((unused))int ac, char *av[])
{
	char *prompt = "/bin/sh: \n";
	char *lineptr = NULL, *linecpy = NULL, *token = NULL;
	size_t n = 0;
	int i, tokens = 0;
	ssize_t line;
	char *delim = " \n";

	while (1)
	{
		write(1, prompt, 9);
		line = getline(&lineptr, &n, stdin);
		if (line == -1)
			return (-1);
		linecpy = malloc(sizeof(char) * line);
		if (!linecpy)
			return (-1);
		strcpy(linecpy, lineptr);
		token = strtok(linecpy, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			tokens++;
		}
		tokens++;
		av = malloc(sizeof(char *) * tokens);
		token = strtok(lineptr, delim);
		for (i = 0; token; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		command(av);
	}
	free(lineptr);
	free(linecpy);
	return (0);
}
