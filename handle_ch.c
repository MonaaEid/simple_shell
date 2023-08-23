#include "shell.h"
/**
 * _putchar - a function that prints one character
 * @currChar: the character will be printed
 * Return: the charcter
 */
int _putchar(int currChar)
{
	return (write(1, &currChar, 1));
}

/**
 * print_string - a function that prints a string
 * @currString: the string will be printed
 * Return: the string
 */
int print_string(char *currString)
{
	int i, len;

	if (currString == NULL)
	{
		currString = "(null)";
		len = _strlen(currString);
		for (i = 0; i < len; i++)
			_putchar(currString[i]);
		return (len);
	}
	else
	{
		len = _strlen(currString);
		for (i = 0; i < len; i++)
			_putchar(currString[i]);
		return (len);
	}
}

