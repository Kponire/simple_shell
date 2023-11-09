#include "shell.h"

int main(void)
{
	char *texts;
	char **bts;
	char *path, *fullpath;
	int builtin_id;
	struct stat buf;

	while (exe)
	{
	_prompt(STDIN_FILENO, buf);
	texts = _getline();
	bts = _strtok(texts, ' ');
	if (strcmp(bts[0], "exit") == 0)
		hsh_exit(bts);
	builtin_id = builtIn(bts);
	printf("%d\n", builtin_id);
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
	printf("Length is %lu\n", strlen(texts));
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
