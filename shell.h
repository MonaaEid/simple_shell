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

int execute_command(char **args);
char *read_line(void);
char **split_line(char *line);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _printf(const char *format, ...);
int _putchar(int currChar);
int print_string(char *currString);
int _strlen(char *s);
int main(void);
char *find_command(char *command);
void exitShell();
char *_getline();
char *enter(char *string);
char *space(char *str);
void hashtag_handler(char *buff);


#endif
