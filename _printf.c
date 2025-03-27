#include "main.h"
#include "_printf.h"
#include <stdio.h>
#include <stdarg.h>
static const GestionarFormato manejar[] = {
	{'c', gestionar_caracter},
	{'s', gestionar_cadena},
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

	if ((formato == NULL) || (formato[0] == '%' && formato[1] == '\0'))
	{
		return (-1);
	}

	va_start(args, formato);
	while (*formato)
	{
		if (*formato == '%')
		{
			encontrado = 0;
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
