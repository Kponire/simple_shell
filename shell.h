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
#define err_malloc "Unable to allocate space on the memory\n"
#define err_path "No such file or directory\n"
#define err_fork "Unable to fork and create child process\n"
extern char **environ;
extern int exit_id;

/**
 * struct builtin - checks if the command is inbuilt in unix
 * @command: the input string
 * @execute: function pointer
 */

typedef struct builtin
{
	char *command;
	int (*execute)(char **);
} built_in;

int _putchar(char c);
void _signal(int cmd);
void _prompt(int fd, struct stat buf);
void _prompt1(void);
char *_getline();
int check_empty(char *texts);
int _strlen(char *s);
void hsh_hash(char *texts);
char **_strtok(char *str, char delim);
char *_getenv(const char *name);
char *_getpath(char *path, char *command);
int _execute(char *fullpath, char **command);
int builtIn(char **tokens);
void hsh_exit(char **token, char *texts);
int hsh_env(__attribute__((unused)) char **token);
int hsh_cd(char **token);
int _setenv(char **token);
int _unsetenv(char **token);
int _echo(char **token);
void print_int(unsigned int number);
void hsh_freeall(char *texts, char **token, char *path, char *fullpath);

#endif
