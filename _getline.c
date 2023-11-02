#include "shell.h"

size_t _getline(char **inputstr, size_t *size, FILE *fp)
{
	char texts[buffsize];

	if (inputstr == NULL || size == NULL)
	{
		fputs("No argument entered!", stderr);
		return (-1);
	}
	if (fp == NULL)
	{
		fputs("Can't access the stdin file!", stderr);
		return (-1);
	}
	*size = sizeof(texts);
	if (*inputstr == NULL)
	{
		*inputstr = malloc(*size);
		if (*inputstr == NULL)
		{
			perror("Unable to allocate enough memory to the buffer");
			free(*inputstr);
			return (-1);
		}
	}
	while (fgets(texts, sizeof(texts), fp) != NULL)
	{
		if (*size - strlen(*inputstr) < sizeof(texts))
		{
			*size *= 2;
			*inputstr = realloc(*inputstr, *size);
			if (*inputstr == NULL)
			{
				perror("Unable to reallocate memory for buffer");
				free(*inputstr);
				return (-1);
			}
		}
		strcat(*inputstr, texts);
		if ((*inputstr)[strlen(*inputstr) - 1] == '\n')
		{
			(*inputstr)[strlen(*inputstr) - 1] = '\0';
			return (strlen(*inputstr));
		}
	}
	return (-1);
}
