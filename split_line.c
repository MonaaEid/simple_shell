#include "shell.h"
/**
 * split_line - function that split a line into tokens
 * @line: the line will be splitted
 * Return: the array of tokens
*/
char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		/*fprintf(stderr, "Error: memory allocation failed.\n");*/
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			free(tokens);
			tokens = malloc(bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				/*fprintf(stderr, "Error: memory allocation failed.\n");*/
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
