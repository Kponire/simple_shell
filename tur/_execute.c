#include "shell.h"

/**
 * _execute - function that execute the execve which takes env, path, command
 * @fullpath: the fullpath
 * @command: the input string
 * Return: 0 which indicates success
 */

int _execute(char *fullpath, char **command)
{
	pid_t proc;
	pid_t wyd;
	int id, status;
	(void) wyd;

	proc = fork();
	if (proc == -1)
	{
		write(STDERR_FILENO, err_fork, strlen(err_fork));
		return (-1);
	}
	if (proc == 0)
	{
		status = execve(fullpath, command, environ);
		if (status == -1)
		{
			write(STDERR_FILENO, err_path, strlen(err_path));
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	else
	{
		do {
			wyd = waitpid(proc, &id, WUNTRACED);
		} while (!WIFEXITED(id) && !WIFSIGNALED(id));
	}
	return (0);
}
