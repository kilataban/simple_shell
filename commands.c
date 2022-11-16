#include "main.h"

/**
 * command - execute the command
 * @av: the arguments
 */
void command(char **av)
{
	char *command = NULL, *comm = NULL;

	if (av)
	{
		command = av[0];
		comm = getCommand(command);

		if (execve(comm, av, NULL) == -1)
			perror("Error: ");
	}
}
