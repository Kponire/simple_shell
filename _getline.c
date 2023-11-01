#include "shell.h"

ssize_t *_getline(char **restrict inputstring, size_t *restrict size, File *restrict filename)
{
	char texts[1024];

	if (inputstring == NULL || line == NULL)
	{
		fputs("No argument entered!", stderr);
		return (-1);
	}
	if (filename == NULL)
	{
		fputs("Can't access the stdin file!", stderr);
		return (-1);
	}
	*size = sizeof(texts);
	if (*inputstring == NULL)
	{
		*inputstring = malloc(*size);
		if (*size == NULL)
		{
			perror("Unable to allocate enough memory to the buffer");
			free(*size);
			return (-1);
		}
	}
	while (fgets(texts, sizeof(texts), filename) != NULL)
	{
		if (*size - strlen(*inputstring) < sizeof(texts))
		{
			*size *= 2;
			*inputstring = realloc(*inputstring, *size);
		}
		strcat(*line, texts);
		if ((*line)[strlen(*line) - 1] == '\n')
			return strlen(*line);
	}
	free(*size);
	return (-1);
}
