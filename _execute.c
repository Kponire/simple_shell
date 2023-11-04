#include "shell.h"

int _execute(char *fullpath, char **command)
{
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
		status = execve(fullpath, command, environ);
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
