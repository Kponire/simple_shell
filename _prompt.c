#include "shell.h"

void _prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
		write(1, "$ ", 2);
}
