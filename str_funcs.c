#include <string.h>
#include "shell.h"
/**
 * is_delim - function to check if a character is a delimiter or not
 * @c: pointer to a char
 * @delim: a size_t variable
 * Return: 0
 */
int is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}
/**
 * _strtok - function to split a string into tokens based on a delimiter
 * @str: pointer to a char
 * @delim: a size_t variable
 * Return: Array of tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *start;

	if (str)
	{
		next = str;
	}
	if (!next)
	{
		return (NULL);
	}
	while (*next && is_delim(*next, delim))
	{
		next++;
	}

	if (!*next)
	{
		return (NULL);    }
		start = next;

	while (*next && !is_delim(*next, delim))
	{
		next++;
	}
	if (*next)
	{
		*next = '\0';
		next++;
	}
	return (start);
}
		/**************************************************************/

/**
 * _strcat - function that appends the src string to the dest string
 * @__dest: pointer to a char
 * @__src: a size_t variable
 * Return: Array of tokens
 */

char *_strcat(char *__restrict__ __dest, const char *__restrict__ __src)
{
	char *p = __dest;

	while (*p != '\0')
	{
		p++;
	}
	while (*__src != '\0')
	{
		*p = *__src;
		p++;
		__src++;
	}
	*p = '\0';
	return (__dest);
}
/**
 * _strchr - function that appends the src string to the dest string
 * @__s: pointer to a char
 * @__c: a size_t variable
 * Return: Array of tokens
 */
char *_strchr(const char *__s, int __c)
{
	if (__s == NULL || *__s == '\0')
	{
		return (NULL);
	}
	while (*__s != '\0')
	{
		if (*__s == (char)__c)
		{
			return ((char *)__s);
		}
	 __s++;
	}
	return (NULL);
}
