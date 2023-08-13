#include <limits.h>
#include <stdio.h>
#include "shell.h"

/**
 * main - Entry point
 * Description:  a UNIX command line interpreter.
 * Return: Always 0 (Success)
 */
/*int main(int ac, char **av)*/
int main(void)
{
	/*FILE *stream;*/
	char *line;
	char **args;
	int status;


	/*(void)ac; (void)av;*/

	do {
			/*write(1, "(monsh) $ ", 11);*/
		_printf("(monsh) $ ");

		line = read_line();

		args = split_line(line);

		status = execute_command(args);

		free(line);

		free(args);

	} while (status);
	return (EXIT_SUCCESS);
}
