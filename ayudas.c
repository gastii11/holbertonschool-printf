#include "main.h"
/**
 * entero_a_cadena - Convierte un entero a cadena ASCII.
 * @num: Número a convertir.
 * @buffer: Donde se almacenará la cadena resultante.
 */
void entero_a_cadena(int num, char *buffer)
{
        int i = 0;
        int es_negativo = 0;

        if (num < 0)
        {
                es_negativo = 1;
                num = -num;
        }

        if (num == 0)
                buffer[i++] = '0';

        while (num > 0)
        {
                buffer[i++] = (num % 10) + '0';
                num /= 10;
        }

        if (es_negativo)
                buffer[i++] = '-';

        buffer[i] = '\0';
        invertir_cadena(buffer);
}

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
