#include "_printf.h"
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
 * gestionar_entero - Procesa el especificador %d.
 * @args: Lista de argumentos variables.
 * @contador: Puntero al contador de caracteres.
 */
void gestionar_entero(va_list *args, int *contador)
{
	int num = va_arg(*args, int);
	char buffer[20];
	entero_a_cadena(num, buffer);
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		_putchar(buffer[i]);
		(*contador)++;
	}
}

/**
 * gestionar_porcentaje - Procesa el especificador %% (imprime '%').
 * @contador: Puntero al contador de caracteres.
 */
void gestionar_porcentaje(int *contador)
{
	_putchar('%');
	(*contador)++;
}
