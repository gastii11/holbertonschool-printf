#include "main.h"
#include "_printf.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 *_strlen -returns the length of a string.
 * @s: is a cstring.
  * Return: length of a string
 */
int _strlen(char *s)
{
	int longitud;
	while (*s != '\0')
	{
		longitud++;
		s++;
	}
	return (longitud);
}

