#ifndef shell_h
#define shell_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define buffsize 1024
extern char **environ;

size_t _getline(char **inputstr, size_t *size, FILE *fp);
char **_strtok(const char *str, char delim);
char *_getenv(const char *name);
char *_getpath(char *path, char *command);
int _execute(char *fullpath, char **command);

#endif
