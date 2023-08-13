#include "shell.h"
/**
 * read_line - function that read a line from the standard input
 *
 * Return: the line
*/
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
