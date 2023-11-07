#include "shell.h"

int _echo(char **token)
{
	char *path;
	pid_t ppid;
	
	ppid = getppid();
	if (strcmp(token[0], "$?") == 0)
	{
		print_int(exit_id);
	}
	if (strcmp(token[1], "$$") == 0)
	{
		print_int(ppid);
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
