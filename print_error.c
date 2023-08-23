#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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
	errmsg[i] = '\0';
	perror(errmsg);
	free(errmsg);
}
