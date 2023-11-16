#include "shell.h"

/**
 * _strtok - function that breaks the getline string into arrays of word
 * @str: the input string
 * @delim: the split
 * Return: array of strings
 */

char **_strtok(char *str, char *delim)
{
	char **tokens, *token;
	unsigned int i = 0;

	tokens = malloc(sizeof(char) * buffsize);
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
