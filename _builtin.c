#include "shell.h"

int builtIn(char *tokens)
{
	int i, status;

	built_in builtin_arr[] = {
		{"exit", hsh_exit},
		{NULL, NULL},
	};
	for (i = 0; builtin_arr[i].command != NULL; i++)
	{
		if (strcmp(builtin_arr[i].command, tokens) == 0)
		{
			status = (builtin_arr[i].execute)();
			return (status);
		}
	}
	return (1);
}
