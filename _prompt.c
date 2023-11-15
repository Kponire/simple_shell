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
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * _prompt1 - prints $ to the stdout
 */

void _prompt1(void)
{
	char *pmt = "($) ";

	write(STDOUT_FILENO, pmt, strlen(pmt));
}
