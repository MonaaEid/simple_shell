#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

 /*char **environ; global variable that holds the environment list */
/**
 * _getenv - function that gets an environment variable without using getenv
 * @name: the arguments will be executed
 * Return: -1
*/
char *_getenv(const char *name)
{
      int i = 0;
      int j;
      
     if (name == NULL || *name == '\0') {
    return NULL;
  }



  while (environ[i] != NULL) {

    char *env = environ[i];
    j = 0;

    while (name[j] != '\0' && env[j] != '\0' && env[j] != '=') {
      if (name[j] != env[j]) {

        break;
      }
      j++;
    }

    if (name[j] == '\0' && env[j] == '=') {
      return env + j + 1;
    }

    i++;
  }

  return NULL;
}

/**
 * _setenv - a function that changes or adds
 * an environment variable without using setenv
 * @name: the arguments will be executed
 * @value: 
 * @overwrite:
 * Return: -1 or 1
*/
/* a function that changes or adds an environment variable without using setenv */
int _setenv(const char *name, const char *value, int overwrite)
{
    char *newstr;

    if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
    {
        errno = EINVAL;
        return (-1);
    }

    if (_getenv(name) != NULL && overwrite == 0)
    {
        return (0);
    }

    newstr = malloc(_strlen(name) + _strlen(value) + 2);
    if (newstr == NULL)
    {
        errno = ENOMEM;
        return (-1);
    }

    sprintf(newstr, "%s=%s", name, value);

    if (putenv(newstr) != 0)
    {
        free(newstr);
        return (-1);
    }

    return (1);
}

int _unsetenv(const char *name)
{
    int i = 0;

    if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
    {
        errno = EINVAL;
        return (-1);
    }

    while (environ[i] != NULL && _strncmp(environ[i], name, _strlen(name)) != 0)
    {
        i++;
    }

    if (environ[i] == NULL)
    {
        return (0);
    }

    free(environ[i]);

    while (environ[i] != NULL)
    {
        environ[i] = environ[i + 1];
        i++;
    }

    return (1);
}
