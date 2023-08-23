#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

 /*char **environ; global variable that holds the environment list */
/**
 * _getenv - function that gets an environment variable without using getenv
 * @name: the arguments will be executed
 * Return: -1
*/
char *_getenv(const char *name)
{
	int i = 0;
	int j;

	if (name == NULL || *name == '\0')
		return (NULL);

	while (environ[i] != NULL)
	{
		char *env = environ[i];

		j = 0;

	while (name[j] != '\0' && env[j] != '\0' && env[j] != '=')
	{
		if (name[j] != env[j])
		{
			break;
		}
		j++;
	}

	if (name[j] == '\0' && env[j] == '=')
		return (env + j + 1);
	i++;
	}
	return (NULL);
}
