#ifndef _SHELL_H_
#define _SHELL_H_

/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define _GNU_SOURCE
#define BUFFER_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif