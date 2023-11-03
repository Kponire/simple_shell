#include "shell.h"

char *_getpath(char *path, char *command)
{
	char **token, *fullpath, *pthcpy, *dir;
	int i = 1, length, dirsize, pthlen;

	length = strlen(command);
	pthlen = strlen(path);
	pthcpy = malloc((sizeof(char) * pthlen) + 1);
	if (!pthcpy)
	{
		free(pthcpy);
		return (NULL);
	}
	strcpy(pthcpy, path);
	token = _strtok(pthcpy, ':');
	dir = token[1];
	while (dir)
	{
		dirsize = strlen(dir);
		fullpath = malloc(sizeof(char) * (length + dirsize + 2));
		if (!fullpath)
		{
			free(fullpath);
			return (NULL);
		}
		strcpy(fullpath, dir);
		fullpath[dirsize] = '/';
		strcat(fullpath, command);
		fullpath[length + dirsize + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			dir = token[++i];
		}
		else
			break;
	}
	free(pthcpy);
	return (fullpath);
}