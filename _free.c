#include "shell.h"

/**
 * hsh_freeall - function that free up the memory
 * @text: the allocated space to store the text
 * @token: the array of strings
 * @path: the path
 * @fullpath: the fullpath
 */

void hsh_freeall(char *text, char **token, char *path, char *fullpath)
{
	free(text);
	free(token);
	free(path);
	free(fullpath);
}

