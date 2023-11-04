#include "shell.h"

void hsh_freeall(char *text, char **token, char *path, char *fullpath)
{
	free(text);
	free(token);
	free(path);
	free(fullpath);
}

