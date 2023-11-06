#include "shell.h"

int hsh_cd(char **token)
{
	if (token[1] == NULL)
		loc = chdir(_getenv("HOME"));
	if (strcmp(token[1], "-") == 0)
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
		getcwd(token, sizeof(token));
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", token, 1);
	}
	return (0);
}
