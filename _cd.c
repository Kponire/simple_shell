#include "shell.h"

int hsh_cd(char **token)
{
	int loc;
	char buffer[PATH_MAX + 1];

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
		getcwd(buffer, sizeof(buffer));
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", buffer, 1);
	}
	return (0);
}
