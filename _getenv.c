#include "shell.h"

char *_getenv(const char *name)
{
	extern char **environ;
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
			length = strlen(enpath);
			envalue = malloc((sizeof(char) * length) + 1);
			if (envalue == NULL)
			{
				free(envalue);
				return (NULL);
			}
			envalue = strcpy(envalue, enpath);
			return (envalue);
		}
		i++;
	}
	return (NULL);
}

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
