#include <limits.h>
#include <stdio.h>
#include "shell.h"

/**
 * main - Entry point
 * @av: argument vector
 * @ac: count of arguments
 * Description:  a UNIX command line interpreter.
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *line;
	char **args;
	int status;
	/*FILE *file;char ch;*/

	(void)ac;
	if (ac < 1)
		return (-1);
	do {
		if (isatty(STDIN_FILENO))
		{
			write(1, "(monsh $)", 9);
		}
		line = read_line();
		if (line == NULL)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		args = split_line(line);
		if (args == NULL)
		{
			free(line);
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		status = execute_command(args, av[0]);
		free(line);
		free(args);

	} while (status);
	return (0);
}

