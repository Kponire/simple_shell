#include "shell.h"

void hsh_exit(char **token)
{
	int i = 0, exit_id;

	if (token[1] == NULL)
	{
		free(token);
		_exit(EXIT_SUCCESS);
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
			_exit(exit_id);
		}
	}
}
