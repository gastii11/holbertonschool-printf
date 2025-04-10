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
