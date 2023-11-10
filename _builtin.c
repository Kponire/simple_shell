#include "shell.h"

/**
 * builtIn - function that checks for the command and implement the fuctions
 * @tokens: the input string
 * Return: 0 which indicates success and 1 to continue
 */

int builtIn(char **tokens)
{
	int i, status;

	built_in builtin_arr[] = {
		{"env", hsh_env},
		{"cd", hsh_cd},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"echo", _echo},
		{NULL, NULL},
	};
	for (i = 0; builtin_arr[i].command != NULL; i++)
	{
		if (strcmp(builtin_arr[i].command, tokens[0]) == 0)
		{
			status = (builtin_arr[i].execute)(tokens);
			return (status);
		}
	}
	return (1);
}
