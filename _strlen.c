#include "shell.h"
#include <stddef.h>

/**
 * _strlen - returns the length of a string.
 * @s: string.
 *
 * Return: length of s.
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
