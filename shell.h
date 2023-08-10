#ifndef _SHELL_H_
#define _SHELL_H_

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

#define _GNU_SOURCE
#define BUFFER_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int _putchar(int currChar);
int print_string(char *currString);
int _printf(const char *format, ...);
int _strlen(char *s);
#endif