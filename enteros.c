#include "main.h"
#include <stdio.h>
#include <limits.h>
#include "_printf.h"
#include <unistd.h>
/**
 * gestionar_entero - Maneja la impresión de enteros.
 * @args: Lista de argumentos variádicos.
 * @contador: Puntero al contador de caracteres impresos.
 */
void gestionar_entero(va_list *args, int *contador)
{
	int num = va_arg(*args, int);
	char buffer[20];
	int i = 0, j;
	unsigned int n;
	char temp;

	if (num == INT_MIN)
	{
		char int_min_str[] = "-2147483648";

		for (j = 0; int_min_str[j]; j++)
		{
			write(1, &int_min_str[j], 1);
			(*contador)++;
		}
		return;
	}

	if (num < 0)
	{
		write(1, "-", 1);
		(*contador)++;
		n = -num;
	}
	else
	{
		n = num;
	}

	do {
		buffer[i++] = n % 10 + '0';
		n /= 10;
	} while (n != 0);

	for (j = 0; j < i / 2; j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}

	for (j = 0; j < i; j++)
	{
		write(1, &buffer[j], 1);
		(*contador)++;
	}
}
