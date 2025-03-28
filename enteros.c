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
	char buffer[20], temp, *int_min = "-2147483648";
	unsigned int n;
	int i = 0, j;

	if (num == INT_MIN)
	{
		for (j = 0; int_min[j]; j++, (*contador)++)
			write(1, &int_min[j], 1);
		return;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		(*contador)++;
	}
	do {
		buffer[i++] = n % 10 + '0';
	} while ((n /= 10) != 0);
	for (j = 0; j < i / 2; j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
	for (j = 0; j < i; j++, (*contador)++)
		write(1, &buffer[j], 1);
}
