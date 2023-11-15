#include "shell.h"

/**
 * hsh_exit - function that closes the shell
 * @token: the input string
 * @texts: the string
 */

void hsh_exit(char **token, char *texts)
{
	int i = 0, exit_id;

	if (token[1] == NULL)
	{
		free(token);
		free(texts);
		exit(EXIT_SUCCESS);
	}
	while (token[1][i])
	{
		if (isalpha(token[1][i++]) != 0)
		{
			perror("please enter an integer");
			break;
		}
		else
		{
			exit_id = atoi(token[1]);
			free(token);
			free(texts);
			exit(exit_id);
		}
	}
}
