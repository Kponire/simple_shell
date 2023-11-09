#include "shell.h"

int _setenv(char **token)
{
	int i = 0;
	char *alloc, **enspt;

	if (!token[1] || !token[2])
	{
		perror("Enter the path and value");
		return (-1);
	}
	while (environ[i])
	{
		enspt = _strtok(environ[i], '=');
		if (strcmp(token[1], enspt[0]) == 0)
		{
			alloc = malloc(strlen(token[1]) + strlen(token[2]) + 2);
			strcpy(alloc, token[1]);
			strcat(alloc, "=");
			strcat(alloc, token[2]);
			strcat(alloc, "\0");
			environ[i] = alloc;
			return (0);
		}
		i++;
	}
	alloc = malloc(strlen(token[1]) + strlen(token[2]) + 2);
	strcpy(alloc, token[1]);
	strcat(alloc, "=");
	strcat(alloc, token[2]);
	environ[i] = alloc;
	environ[++i] = NULL;
	return (0);
}


int _unsetenv(char **token)
{
	int i = 0, unset, j;
	char **enspt, **newenv;

	if (token[1] == NULL)
	{
		perror("Please enter the path");
		return (0);
	}
	while (environ[i] != NULL)
	{
		enspt = _strtok(environ[i], '=');
		if (strcmp(enspt[0], token[1]) == 0)
		{
			unset = i;
		}
		i++;
	}
	if (unset == -1)
	{
		perror("Can't find the path in the environment variables");
		return (1);
	}
	newenv = malloc(sizeof(char *) * i);
	for (i = j = 0; environ[i]; i++)
	{
		if (i != unset)
		{
			newenv[j] = environ[i];
			j++;
		}
	}
	newenv[j] = NULL;
	/*free(environ[unset]);
	free(environ);*/
	environ = newenv;
	return (0);
}