#include "shell.h"

/**
 * _echo - function that implements the echo builtin command in unix
 * @token: the inpit string
 * Return: 0 which indicates success otherwise 1
 */

int _echo(char **token)
{
	char *path;
	pid_t ppid;

	ppid = getppid();
	if (strcmp(token[1], "$?") == 0)
	{
		print_int(0);
		return (0);
	}
	if (strcmp(token[1], "$$") == 0)
	{
		print_int(ppid);
		return (0);
	}
	if (strcmp(token[1], "$PATH") == 0)
	{
		path = _getenv("PATH");
		write(STDOUT_FILENO, path, strlen(path));
		free(path);
		return (0);
	}
	return (1);
}
