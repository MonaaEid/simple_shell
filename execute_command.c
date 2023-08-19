#include "shell.h"

/**
 * execute_command - function that execute a command
 * @args: the arguments will be executed
 * Return: the exit status of the child process or 1 or -1
*/
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}
	if (_strcmp(args[0], "exit") == 0)
		return (0);
	if (_strcmp(args[0], "env") == 0)
		return (env_builtin());
	if (_strcmp(args[0], "cd") == 0)
		status = cd_builtin(args);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		/*if (execvp(args[0], args) == -1)*/
		if (execve(args[0], args, NULL) == -1)
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
        _printf("%s\n", environ[i]);
        i++;
    }
    return (1);
}
