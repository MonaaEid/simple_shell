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
/*int main(void)*/
{
	/*FILE *stream;*/

	char *line;
	char **args;
	int status;

	(void)ac;
	(void)av;

	do {
		write(1, "(monsh) $ ", 11);

		line = read_line();

		args = split_line(line);

		status = execute_command(args, av[0]);

		free(line);
		free(args);

	} while (status);
	return (EXIT_SUCCESS);
}
