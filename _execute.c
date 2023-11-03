#include "shell.h"

int _execute(char *fullpath, char **command)
{
	char **env = environ;
	pid_t proc;
	int id, status;

	proc = fork();
	if (proc == -1)
	{
		fputs("Unable to create a child process\n", stderr);
		return (-1);
	}
	if (proc == 0)
	{
		status = execve(fullpath, command, env);
		if (status == -1)
		{
			fputs("Unable to execute the command\n", stderr);
			return (-1);
		}
	}
	else
	{
		wait(&id);
	}
	return (0);
}
