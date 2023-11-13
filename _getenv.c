#include "shell.h"

/**
 * _getenv - function that searches for the path of the environment variable
 * @name: the path to be searched
 * Return: the value of the path or null if not found
 */

char *_getenv(const char *name)
{
	char **token, *envalue, *enpath;
	int i = 0, length;

	if (name == NULL)
		return (NULL);
	while (environ[i])
	{
		token = _strtok(environ[i], '=');
		if (strcmp(token[0], name) == 0)
		{
			enpath = token[1];
			if (strcmp(enpath, "\0") == 0)
			{
				write(STDERR_FILENO, err_path, strlen(err_path));
				exit(EXIT_FAILURE);
			}
			length = strlen(enpath);
			envalue = malloc((sizeof(char) * length) + 1);
			if (envalue == NULL)
			{
				free(envalue);
				write(STDERR_FILENO, err_malloc, strlen(err_malloc));
				return (NULL);
			}
			envalue = strcpy(envalue, enpath);
			return (envalue);
		}
		i++;
	}
	return (NULL);
}

/**
 * hsh_env - implement the builtin in unix which prints the whole variables
 * @token: the environment variables
 * Return: 0 which indicates success
 */

int hsh_env(__attribute__((unused)) char **token)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
