#include "shell.h"

int main(void)
{
	char *texts;
	size_t i = 0;
	ssize_t bty;
	char **bts;
	char *path, *fullpath;
	/*int builtin_id;*/
	struct stat buf;

	while (exe)
	{
	fflush(stdin);
	texts = NULL;
	_prompt(STDIN_FILENO, buf);
	bty = _getline(&texts, &i, stdin);
	bts = _strtok(texts, ' ');
	if (strcmp(bts[0], "exit") == 0)
		hsh_exit(bts);
	/*builtin_id = builtIn(bts);
	printf("%d\n", builtin_id);
	if (builtin_id == -1 || builtin_id == 0)
		free(bts);
	if (builtin_id == -1)
		_exit(EXIT_SUCCESS);
	else
		_exit(builtin_id);*/
	path = _getenv("PATH");
	fullpath = _getpath(path, bts[0]);
	if (fullpath == NULL)
	{
		fullpath = bts[0];
	}
	printf("Length is %lu\n", bty);
	printf("The string is %s\n", texts);
	printf("The first string is %s\n", bts[0]);
	printf("path value is %s\n", path);
	printf("Fullpath is %s\n", fullpath);
	_execute(fullpath, bts);
	/* hsh_free(texts, bts, path, fullpath); */
	free(texts);
	free(bts);
	free(path);
	free(fullpath);
	}
	return (0);
}
