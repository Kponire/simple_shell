#include "shell.h"

/**
 * _execute - function that execute the execve which takes env, path, command
 * @fullpath: the fullpath
 * @command: the input string
 * Return: 0 which indicates success
 */

int _execute(char *fullpath, char **command)
{
	int status;

	status = execve(fullpath, command, environ);
	if (status == -1)
	{
		write(STDERR_FILENO, err_path, strlen(err_path));
		exit(EXIT_FAILURE);
	}
	return (0);
}
