#include "_printf.h"
#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
/**
 * gestionar_caracter - Procesa el especificador %c.
 * @args: Lista de argumentos variables.
 * @contador: Puntero al contador de caracteres.
 */
void gestionar_caracter(va_list *args, int *contador)
{
	char c = va_arg(*args, int);
	
	_putchar(c);
	(*contador)++;
}

/**
 * gestionar_cadena - Procesa el especificador %s.
 * @args: Lista de argumentos variables.
 * @contador: Puntero al contador de caracteres.
 */
void gestionar_cadena(va_list *args, int *contador)
{
	char *cadena = va_arg(*args, char *);

	if (!cadena)
		cadena = "(null)";
	while (*cadena)
	{
		_putchar(*cadena);
		cadena++;
		(*contador)++;
	}
}


/**
 * gestionar_porcentaje - Procesa el especificador %% (imprime '%').
 * @contador: Puntero al contador de caracteres.
 */
void gestionar_porcentaje(va_list *args, int *contador)
{
	(void)args;
	_putchar('%');
	(*contador)++;
}

/**
 * gestionar_invalido - Procesa especificadores no válidos (ej: %#).
 * @caracter_invalido: Carácter inválido después de %.
 * @contador: Puntero al contador de caracteres.
 */
void gestionar_invalido(char caracter_invalido, int *contador)
{
	_putchar('%');
	_putchar(caracter_invalido);
	*contador += 2;
}


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
