#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#define NUM_BUILTINS 3

/**
 * cd_builtin - changes the current directory of the process
 * @args: array of arguments
 * Return: 1 if success, -1 if error
 */
int cd_builtin(char **args)
{
	char *path;
	char *oldpwd;
	char *pwd;

	oldpwd = _getenv("PWD");
	if (args[1] == NULL)
		path = _getenv("HOME");
	else if (_strcmp(args[1], "-") == 0)
	{
		path = _getenv("OLDPWD");
		_printf("%s\n", path);
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		perror("Error changing directory");
		return (-1);
	}
	pwd = getcwd(NULL, 0);

	if (_setenv("OLDPWD", oldpwd, 1) == -1)
	{
		perror("Error setting OLDPWD");
		return (-1);
	}
	else if (_setenv("PWD", pwd, 1) == -1)
	{
		perror("Error setting PWD");
		return (-1);
	}
free(pwd);
return (1);
}

int is_builtin(char *cmd)
{
	int i;
	char *builtins[] = {"exit", "cd", "help"};

	for (i = 0; i < NUM_BUILTINS; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}