#include "shell.h"

/**
 * _getline - function that accepts input from the user using stdin
 * Return: the input string
 */

char *_getline()
{
	int i = 0, bs, buffer = buffsize;
	char *texts, c = 'z';

	texts =  malloc(sizeof(char) * buffer);
	if (texts == NULL)
	{
		free(texts);
		return (NULL);
	}
	fflush(stdin);
	while (c != EOF && c != '\n')
	{
		bs = read(STDIN_FILENO, &c, 1);
		if (bs == 0)
		{
			free(texts);
			exit(EXIT_SUCCESS);
		}
		texts[i] = c;
		if (texts[0] == '\n')
		{
			free(texts);
			return ("\0");
		}
		if (i >= buffer)
		{
			buffer *= 2;
			texts = realloc(texts, buffer);
			if (texts == NULL)
			{
				free(texts);
				return (NULL);
			}
		}
		i++;
	}
	texts[--i] = '\0';
	hsh_hash(texts);
	return (texts);
}
/**
 * hsh_hash - removes every command after the # character
 * @texts: the input string from the stdin
 */

void hsh_hash(char *texts)
{
	int i = 0;

	for (i = 0; texts[i] != '\0'; i++)
	{
		if (texts[i] == '#')
		{
			texts[i] = '\0';
			break;
		}
	}
}
