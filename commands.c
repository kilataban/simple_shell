#include "main.h"

/**
 * command - execute command
 * @av: the arguments
 */
void command(char *av[])
{
	char *command = NULL, *comm = NULL;
	pid_t cpid;
	int status;

	if (av)
	{
		command = av[0];
		comm = execu(command);	
		cpid = fork();

		if (cpid == 0)
		{
			if (execve(comm, av, NULL) == -1)
				perror("Error");
		}
		else
		{
			waitpid(cpid, &status, WUNTRACED);
		}

	}
}
