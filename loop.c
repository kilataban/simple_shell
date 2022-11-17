#include "main.h"

/**
 * main - control the loop
 * @ac: count
 * @av: arguments
 * Return: 0
 */
int main(__attribute__((unused))int ac, char *av[])
{
	char *prompt = "#cisfun$ ";
	char *buffer = NULL, *buffcpy = NULL, *token;
	int tokens = 0, i = 0;
	ssize_t line;
	size_t n = 0;

	while (1)
	{
		write(1, prompt, 9);
		line = getline(&buffer, &n, stdin);
		if (line == -1)
			return (-1);
		buffcpy = malloc(sizeof(char) * line);
		if (!buffcpy)
			return (-1);
		strcpy(buffcpy, buffer);

		token = strtok(buffer, " \n");
		while (token)
		{
			token = strtok(NULL, " \n");
			tokens++;
		}
		tokens++;
		av = malloc(sizeof(char *) * tokens);

		token = strtok(buffcpy, " \n");
		for (i = 0; token; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, " \n");
		}
		av[i] = NULL;
		execu(av);
	}
	free(buffcpy);
	free(buffer);

	return (0);
}
