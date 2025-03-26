#include "main.h"
#include "_printf.h"
#include <stdio.h>

static const GestionarFormato manejar[] = {
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
	int contador = 0, encontrado = 0;
	int i = 0;

	va_start(args, formato);
	while (*formato)
	{
		if (*formato == '%')
		{
			formato++;

			for (i = 0; i < (int)(sizeof(manejar) / sizeof(manejar[0])); i++)
			{
				if (*formato == manejar[i].especificador)
				{
					manejar[i].manejar(&args, &contador);
					encontrado = 1;
					break;
				}
			}
			if (!encontrado)
				gestionar_invalido(*formato, &contador);
			formato++;
		}
		else
		{
			_putchar(*formato);
			contador++;
			formato++;
		}
	}
	va_end(args);
	return (contador);
}
