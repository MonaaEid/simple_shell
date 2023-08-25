#ifndef _SHELL_H_
#define _SHELL_H_

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
/*#define BUFSIZE 1024*/
#define DELIM " \t\r\n\a"
#define _GNU_SOURCE
#define BUFFER_SIZE 1024
extern char **environ;

/*PRINT FUNCTIONS*/
int _printf(const char *format, ...);
int _putchar(int currChar);
int print_string(char *currString);
/* LINE HANDLER FUNCTIONS*/
char *read_line(void);
char **split_line(char *line);
/*char *_getline();*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


/*STRING FUNCTIONS*/
int _strcmp(const char *__s1, const char *__s2);
char *_strtok(char *str, const char *delim);
size_t _strlen(const char *s);
char *_strcat(char *__restrict__ __dest, const char *__restrict__ __src);
int _strncmp(const char *__s1, const char *__s2, size_t __n);
int _atoi(const char *nptr);

int is_delim(char c, const char *delim);
char *_strchr(const char *__s, int __c);

/*EXECUTION FUNCTIONS*/
int execute_command(char **args, char *av);
/*int execute_command(char **args, char *progname);*/
int execute_builtin(char **args);
char *find_command(const char *command);
int _execvp(const char *file, char *const argv[]);
void print_error(char *progname, char *arg);
/*char *find_command(char **dirs, char *cmd);*/

/*ENVIRONMENT FUNCTIONS*/
int env_builtin(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/*BUILTIN FUNCTIONS HANDLER*/
int cd_builtin(char **args);
int is_builtin(char *cmd);
void hashtag_handler(char *buff);
void exit_cmd(char **args);

char *space(char *str);
char *enter(char *string);
/*void exitShell();*/

void print_number(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);

#endif
