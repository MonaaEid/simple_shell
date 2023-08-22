#include "shell.h"
/*
 *main - Main function of shell
 *find_command - function prints the command
 *Return: 0 if success and null if not
 *
 *
 */
char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		char *cmd_path = malloc(strlen(dir) + strlen(command) + 2);

		sprintf(cmd_path, "%s/%s", dir, command);
		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
