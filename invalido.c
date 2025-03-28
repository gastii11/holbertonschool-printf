#include "_printf.h"
#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
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
