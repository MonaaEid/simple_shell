#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * execute_builtin - function that executes a built-in command
 * @args: the arguments will be executed
 * Return: the exit status of the child process or 1
*/

int execute_builtin(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		cd_builtin(args);
	}
	return (1);
}
/**
 * execute_command - function that execute a command
 * @args: the arguments will be executed
 * Return: the exit status of the child process or 1 or -1
*/
int execute_command(char **args)
{
	pid_t pid;
	int status;
    /*char *dirs[]= {"/bin", "/usr/bin", "/usr/local/bin", NULL};*/

	if (args[0] == NULL)
	{
		return (1);
	}
	if (is_builtin(args[0]))
	{
		return (execute_builtin(args));
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (_execvp(args[0], args) == -1)
		/*if (execve(args[0], args, environ) == -1)*/
		/*if (execve(args[0], args, NULL) == -1)*/
		{
			perror(args[0]);
		}
		exit(EXIT_FAILURE);
	}

	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			return (WEXITSTATUS(status));
	}
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
		/*_printf("%s\n", environ[i]);*/
		i++;
	}
	return (1);
}
/**
 * find_command - function prints the command
 * @command: the arguments will be executed
 * Return: the exit status of the child process or 1 or -1
*/
char *find_command(const char *command)
{
	char *path = _getenv("PATH");
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		char *cmd_path = malloc(_strlen(dir) + _strlen(command) + 2);

		cmd_path[0] = '\0';
		_strcat(cmd_path, dir);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, command);
		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
/**
 * _execvp - function that execute a command
 * @argv: the arguments will be executed
 * @file: a file
 * Return: -1
*/
int _execvp(const char *file, char *const argv[])
{
	char **envp = environ;

	if (_strchr(file, '/') != NULL)
	{
		execve(file, argv, envp);
	}
	else
	{
		char *cmd_path = find_command(file);

		if (cmd_path != NULL)
		{
			execve(cmd_path, argv, envp);
			free(cmd_path);
		}
		else
		{
			errno = ENOENT;
		}
	}
	return (-1);
}
