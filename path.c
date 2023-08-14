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

int main(void)
{
	char input[256];

	printf("Simple Shell> ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	char *command = strtok(input, " ");
	char *cmd_path = find_command(command);

	if (cmd_path != NULL)
	{
		printf("Executing: %s\n", cmd_path);

		free(cmd_path);
	}
	else
	{
		printf("Command not found: %s\n", command);
	}

	return (0);
}

