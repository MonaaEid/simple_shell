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

/*#define BUFSIZE 1024*/
#define DELIM " \t\r\n\a"
#define _GNU_SOURCE
#define BUFFER_SIZE 1024
extern char **environ;
int execute_command(char **args);
int env_builtin(void);
char *read_line(void);
char **split_line(char *line);
char *_getline();
void hashtag_handler(char *buff);
char *space(char *str);
char *enter(char *string);

int _printf(const char *format, ...);
int _putchar(int currChar);
int print_string(char *currString);
size_t _strlen(const char *s);
int is_delim(char c, const char *delim);
char *_strtok(char *str, const char *delim);
int cd_builtin(char **args);

int _strcmp(const char *__s1, const char *__s2);
char *find_command(char *command);
void exitShell();

#endif
