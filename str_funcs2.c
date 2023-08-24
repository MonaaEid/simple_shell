#include <string.h>
#include "shell.h"
/**
 * _strcmp - function to compare two strings lexicographically
 * @__s1: pointer to a char
 * @__s2: a size_t variable
 * Return: Array of tokens
 */
int _strcmp(const char *__s1, const char *__s2)
{
	while (*__s1 && *__s2)
	{
	if (*__s1 != *__s2)
	{
		return (*__s1 - *__s2);
	}
	__s1++;
	__s2++;
	}
	return (_strlen(__s1) - _strlen(__s2));
}
/**
 * _strncmp - function to compare two strings lexicographically
 * @__s1: pointer to a char
 * @__s2: a size_t variable
 * @__n: number of cg
 * Return: Array of tokens
 */
int _strncmp(const char *__s1, const char *__s2, size_t __n)
{
	while (__n > 0 && *__s1 != '\0' && *__s2 != '\0')
	{
		if (*__s1 != *__s2)
		{
			return ((int) (*__s1 - *__s2));
		}
		__s1++;
		__s2++;
		__n--;
	}
	if (__n == 0)
	{
		return (0);
	}
	return ((int) (*__s1 - *__s2));
}
/**
 * _atoi - function to convert a string to an integer
 * @nptr: pointer to a char
 * Return: Array of tokens
 */

int _atoi(const char *nptr)
{
        int result = 0;
        int sign = 1;
        int i = 0;

        while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n')
                i++;

        if (nptr[i] == '+' || nptr[i] == '-')
        {
                if (nptr[i] == '-')
                        sign = -1;
                i++;
        }

        while (nptr[i] != '\0')
        {
                if (nptr[i] >= '0' && nptr[i] <= '9')
                {
                        result = result * 10 + (nptr[i] - '0');
                }
                else
                        break;
                i++;
        }
        return (result * sign);
}
