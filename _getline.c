#include "shell.h"

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
	while (c != EOF || c != '\n')
	{
		bs = read(STDIN_FILENO, &c, 1);
		if (bs == 0)
		{
			free(texts);
			_exit(EXIT_SUCCESS);
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
	texts[i] = '\0';
	return (texts);
}
