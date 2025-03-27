#include "_printf.h"
#include "main.h"
#include <stdio.h>

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


