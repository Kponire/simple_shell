#include "shell.h"

char **_strtok(const char *str, char delim)
{
	char **tokens;
	char text[buffsize];
	int i, j = 0, k = 0;
	int size, len;

	tokens = (char **)malloc(sizeof(text) * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}
	size = strlen(str);
	for (len = 0; len < size; len++)
	{
		tokens[len] = malloc(sizeof(text));
	}
	for (i = 0; i <= size; i++)
	{
		if (str[i] == delim || str[i] == '\0')
		{
			text[j] = '\0';
			strcpy(tokens[k], text);
			j = 0;
			k++;
		}
		else
		{
			text[j] = str[i];
			j++;
		}
	}
	return (tokens);
}
