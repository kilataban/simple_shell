#include "main.h"

/**
 * execu - execute the commands
 * @av: the argument
 */
void execu(char **av, char *envp[])
{
	char *command = NULL;
	pid_t cpid;
	int status;

	if (av)
	{
		command = getPath(av[0]);
		cpid = fork();

		if (cpid == 0)
		{
			if (execve(command, av, envp) == -1)
				return;
		}
		else
			waitpid(cpid, &status, WUNTRACED);
	}
}
