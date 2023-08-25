#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#define NUM_BUILTINS 3
#define ERR_MSG "shell: exit: invalid argument\n"

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
		/*_printf("%s\n", path);*/
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		perror("Error changing directory");
		return (-1);
	}
	pwd = getcwd(NULL, 0);

	if (setenv("OLDPWD", oldpwd, 1) == -1)
	{
		perror("Error setting OLDPWD");
		return (-1);
	}
	else if (setenv("PWD", pwd, 1) == -1)
	{
		perror("Error setting PWD");
		return (-1);
	}
	free(pwd);
	return (1);
}
/**
 * is_builtin - function to check if is built in or not
 * @cmd: array of arguments
 * Return: 1 if success, 0 if error
 */
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

/**
 * exit_cmd - function to handle exit() with arguments
 * @args: pointer to a char
 * Return: Array of tokens
 */
void exit_cmd(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		if (status < 0 || status > 255)
		{
			write(2, ERR_MSG, sizeof(ERR_MSG));
			return;
		}
	}
	exit(status);
}
/**
 * env_builtin - prints the current environment
 * Return: 1 if success, -1 if error
 */
int env_builtin(void)
{
        int i = 0;

        while (environ[i] != NULL)
        {
                write(1, environ[i], _strlen(environ[i]));
                write(1, "\n", 1);
                i++;
        }
        return (1);
}
