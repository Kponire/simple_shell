#include "shell.h"

/**
 * _strtok - function that breaks the getline string into arrays of word
 * @str: the input string
 * @delim: the split
 * Return: array of strings
 */

char **_strtok(const char *str, char delim)
{
	char **tokens;
	char text[buffsize];
	int i, j = 0, k = 0;
	int size;

	tokens = (char **)malloc(sizeof(text) * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		write(STDERR_FILENO, err_malloc, strlen(err_malloc));
		exit(EXIT_FAILURE);
	}
	size = strlen(str);
	for (i = 0; i <= size; i++)
	{
		if (str[i] == delim || str[i] == '\0')
		{
			text[j] = '\0';
			if (text[0] != '\0')
			{
				tokens[k] = strdup(text);
				k++;
			}
			j = 0;
		}
		else
		{
			text[j] = str[i];
			j++;
		}
	}
	tokens[k] = NULL;
	return (tokens);
}
