#include "main.h"
#include "_printf.h"
#include <stdio.h>

static const GestionarFormato gestionadores[] = {
	{'c', gestionar_caracter},
	{'s', gestionar_cadena},
	{'d', gestionar_entero},
	{'%', gestionar_porcentaje}
};

/**
 * _printf - Versoin personalizada de printf
 * @formato: Cadana con texto y especificadores
 * Return: numero de caracteres impresos
 */
int _printf(const char *formato, ...)
{
	va_list args;
	int contador = 0;
	int encontrado;

	va_start(args, formato);
