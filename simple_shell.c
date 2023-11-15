#include "shell.h"

/**
 * main - function that mimics the Bourne-again SHell
 * Return: 0 which indicates success
 */

int main(void)
{
	char *texts, **bts, *path, *fullpath;
	int builtin_id;
	/*struct stat buf;*/

	signal(SIGINT, _signal);
	while (exe)
	{
		/*_prompt(STDIN_FILENO, buf);*/
		if (isatty(STDIN_FILENO))
			_prompt1();
		texts = _getline();
		bts = _strtok(texts, ' ');
		if (strcmp(bts[0], "exit") == 0)
			hsh_exit(bts);
		builtin_id = builtIn(bts);
		if (builtin_id == 0)
		{
			free(texts);
			free(bts);
			continue;
		}
		path = _getenv("PATH");
		fullpath = _getpath(path, bts[0]);
		if (fullpath == NULL)
		{
			fullpath = bts[0];
		}
		_execute(fullpath, bts);
		hsh_freeall(texts, bts, path, fullpath);
	}
	return (0);
}
