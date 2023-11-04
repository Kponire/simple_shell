#include "shell.h"

int main(void)
{
	char *texts;
	size_t i = 0;
	ssize_t bty;
	char **bts;
	char *path, *fullpath;
	int builtin_id;
	struct stat buf;

	while (exe)
	{
	_prompt(STDIN_FILENO, buf);
	texts = NULL;
	bty = _getline(&texts, &i, stdin);
	bts = _strtok(texts, ' ');
	/*id = _built(bts[0]);
	printf("%d\n", id);*/
	builtin_id = builtIn(bts[0]);
	printf("%d\n", builtin_id);
	if (builtin_id == -1 || builtin_id == 0)
	{
		free(bts);
	};
	if (builtin_id == -1)
	{
		_exit(EXIT_SUCCESS);
	};
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
