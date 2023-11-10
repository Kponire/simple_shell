#include "shell.h"

/**
 * _prompt - the prints $ to the stdout
 * @fd: the file descriptor
 * @buf: the struct stat
 */

void _prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
		write(1, "$ ", 2);
}
