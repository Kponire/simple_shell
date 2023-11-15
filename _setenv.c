#include "shell.h"

/**
 * _setenv - function that adds a new environment variable
 * @token: the input string
 * Return: 0 which indicates success otherwise -1
 */

int _setenv(char **token)
{
	int i = 0;
	char *alloc, **enspt;

	if (!token[1] || !token[2])
	{
		write(STDERR_FILENO, err_path, _strlen(err_path));
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

/**
 * _unsetenv - deletes an environment variable
 * @token: the variable
 * Return: 0
 */

int _unsetenv(char **token)
{
	int i = 0, unset = -1, j;
	char **enspt, **newenv;

	if (token[1] == NULL)
	{
		write(STDERR_FILENO, err_path, _strlen(err_path));
		return (-1);
	}
	while (environ[i] != NULL)
	{
		enspt = _strtok(environ[i], '=');
		if (strcmp(enspt[0], token[1]) == 0)
		{
			unset = i;
		}
		free(enspt);
		i++;
	}
	if (unset == -1)
	{
		write(STDERR_FILENO, err_path, _strlen(err_path));
		return (-1);
	}
	newenv = malloc(sizeof(char *) * i);
	if (newenv == NULL)
	{
		free(newenv);
		return (-1);
	}
	for (i = j = 0; environ[i]; i++)
	{
		if (i != unset)
		{
			newenv[j] = environ[i];
			j++;
		}
	}
	newenv[j] = NULL;
	environ = newenv;
	return (0);
}
