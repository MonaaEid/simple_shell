#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/**
 * print_error - prints the error message
 * @progname: programme name
 * @arg: arguments
' * Return: 1 if success, -1 if error
 */
void print_error(char *progname, char *arg)
{
	char *errmsg;
	int i, j;

	errmsg = malloc(_strlen(progname) + _strlen(arg) + 6);
	if (errmsg == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	j = 0;
	while (progname[j] != '\0')
	{
		errmsg[i] = progname[j];
		i++;
		j++;
	}
	errmsg[i] = ':';
	i++;
	errmsg[i] = ' ';
	i++;
	errmsg[i] = '1';
	i++;
	errmsg[i] = ':';
	i++;
	errmsg[i] = ' ';
	i++;
	j = 0;
	while (arg[j] != '\0')
	{
		errmsg[i] = arg[j];
		i++;
		j++;
	}
    /*write(1, "not found", 10);*/
	errmsg[i] = '\0';
	perror(errmsg);
	free(errmsg);
}
