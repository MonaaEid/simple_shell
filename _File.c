#include "shell.h"
/**
 * fillarguments - divide a string and fill an array with each word
 * @buf: buffer which contains the string
 * @separator: separator use to split the buffer
 *
 * Return: array of words
 */
char **fillarguments(char *buf, char *separator)
{
	char **arr = NULL;
	char *token;
	int i = 0, length;

	if (buf == NULL && separator == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (number_of_words(buf, separator) + 1));
	if (arr == NULL)
		return (NULL);

	token = _strtok(buf, separator);
	while (token)
	{
		if (token[0] == '\n')
			break;
		arr[i++] = token;
		token = _strtok(NULL, separator);
	}
	if (i != 0)
	{
		length = _strlen(arr[i - 1]);
		if (arr[i - 1][length - 1] == '\n')
			arr[i - 1][length - 1] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
