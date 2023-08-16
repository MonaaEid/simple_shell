#include "shell.h"
#define CmLength 100

/**
 *main - Entry point
 *Description: Function to exit shell
 *void exitShell(void): Function to exit the shell
 *@CmLength: variable of length
 *Return: Always (0)
 *
 *
 */

void exitShell(void)
{
	printf("Exiting the shell.\n");
	exit(0);
}
int main(void)
{
	char input[CmLength];

	while (1)
	{
		printf("$ ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			exitShell(void);
		} else
			system(input);

	}
	return (0);
}
