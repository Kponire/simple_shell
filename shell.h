#ifndef shell_h
#define shell_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#define buffsize 1024
#define exe 1
extern char **environ;
extern int exit_id;

typedef struct builtin
{
	char *command;
	int (*execute)(char **);
} built_in;

void _prompt(int fd, struct stat buf);
size_t _getline(char **inputstr, size_t *size, FILE *fp);
char **_strtok(const char *str, char delim);
char *_getenv(const char *name);
char *_getpath(char *path, char *command);
int _execute(char *fullpath, char **command);
/*int _built(char *param);*/
int builtIn(char **tokens);
void hsh_exit(char **token);
int hsh_env(__attribute__((unused)) char **token);
int hsh_cd(char **token);
int _setenv(char **token);
int _unsetenv(char **token);
int _echo(char **token);
void print_int(unsigned int number);
void hsh_free(char *text, char **token, char *path, char *fullpath);

#endif
