#include "main.h"

/**
 * main - entry poinnt
 * @ac: the count
 * @av: the vector
 * Return: 0
 */
int main(__attribute__((unused))int ac, char *av[])
{
	ssize_t line;
	size_t n = 0;
	char *buffer = NULL, *buffcpy = NULL, *token = NULL;
	char *prompt = "/bin/sh: \n";
	int i, tokens = 0;

	while (1)
	{
		write(1, prompt, 9);
		line = getline(&buffer, &n, stdin);

		if (line == -1)
			return (-1);
		if (strcmp(buffer, "exit") == 0)
			return (0);
		buffcpy = malloc(sizeof(char) * line);
		if (!buffcpy)
			return (-1);
		strcpy(buffcpy, buffer);
		token = strtok(buffcpy, " \n");
		while (token)
		{
			token = strtok(NULL, " \n");
			tokens++;
		}
		tokens++;
		av = malloc(sizeof(char *) * tokens);
		token = strtok(buffer, " \n");
		for (i = 0; token; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, " \n");
		}
		av[i] = NULL;
		command(av);
	}
	free(buffcpy);
	free(buffer);
	return (0);
}
