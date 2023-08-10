#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: string.
 *
 * Return: length of s.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		continue;
	return (i);
}