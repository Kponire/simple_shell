#include "shell.h"

/**
 * hsh_cd - function that implements the builtin change directory in unix
 * @token: the input string
 * Return: 0 which indicates success
 */

int hsh_cd(char **token)
{
	int loc;
	char buffer[PATH_MAX + 1], *mns;

	if (token[1] == NULL || strcmp(token[1], "~") == 0)
		loc = chdir(_getenv("HOME"));
	else if (strcmp(token[1], "-") == 0)
		loc = chdir(_getenv("OLDPWD"));
	else
		loc = chdir(token[1]);
	if (loc == -1)
	{
		perror("Error locating dir");
		return (-1);
	}
	else
	{
		mns = _getenv("PWD");
		getcwd(buffer, sizeof(buffer));
		setenv("OLDPWD", mns, 1);
		setenv("PWD", buffer, 1);
	}
	free(mns);
	return (0);
}
