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
