#include "shell.h"

/**
 * main - function that mimics the Bourne-again SHell
 * Return: 0 which indicates success
 */

int main(void)
{
	char *texts, **bts, *path, *fullpath;
	int builtin_id;

	signal(SIGINT, _signal);
	while (exe)
	{
		if (isatty(STDIN_FILENO))
			_prompt1();
		texts = _getline();
		if (strcmp(texts, "\0") == 0)
			continue;
		if ((int)strlen(texts) == check_empty(texts))
		{
			free(texts);
			continue;
		}
		bts = _strtok(texts, "\n\t\r ");
		if (strcmp(bts[0], "exit") == 0)
			hsh_exit(bts, texts);
		builtin_id = builtIn(bts);
		if (builtin_id == 0 || builtin_id == -1)
		{
			free(texts);
			free(bts);
			continue;
		}
		path = _getenv("PATH");
		fullpath = _getpath(path, bts[0]);
		if (fullpath == NULL)
		{
			write(STDERR_FILENO, err_path, _strlen(err_path));
			hsh_freeall(texts, bts, path, fullpath);
			continue;
		}
		_execute(fullpath, bts);
		hsh_freeall(texts, bts, path, fullpath);
	}
	return (0);
}
