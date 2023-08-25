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
		return (EXIT_SUCCESS);
	}
	if (_strcmp(args[0], "env") == 0)
		return (env_builtin());
	if (strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
		{
			perror("Usage");
			return (1);
		}
		if (setenv(args[1], args[2], 1) == -1)
		{
			perror("setenv");
			return (1);
		}
		return (0);
	}
	if (strcmp(args[0], "unsetenv") == 0)
	{
	if (args[1] == NULL || args[2] != NULL)
	{
		perror("Usage");
		return (1);
	}
	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
	}
	return (1);
}
/**
 * execute_command - function that execute a command
 * @args: the arguments will be executed
 * @av:program name
 * Return: the exit status of the child process or 1 or -1
*/
int execute_command(char **args, char *av)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		/*perror(args[0]);*/
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
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			(isatty(STDIN_FILENO)) ? perror(av) : print_error(av, args[0]);
			/*perror(av);*/
			exit(EXIT_FAILURE);
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
