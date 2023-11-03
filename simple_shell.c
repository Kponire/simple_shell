#include "shell.h"

int main(void)
{
	char *texts = NULL;
	size_t i = 0;
	ssize_t bty;
	char **bts;
	char *path, *fullpath;

	bty = _getline(&texts, &i, stdin);
	bts = _strtok(texts, ' ');
	path = _getenv("PATH");
	fullpath = _getpath(path, bts[0]);
	printf("Length is %lu\n", bty);
	printf("The string is %s\n", texts);
	printf("The first string is %s\n", bts[0]);
	printf("path value is %s\n", path);
	printf("Fullpath is %s\n", fullpath);
	_execute(fullpath, bts);
	/*while (true)
	{
		textinput = _getline(stdin);
	*/
	return (0);
}
