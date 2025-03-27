#ifndef MI_PRINTF_H
#define MI_PRINTF_H

#include <stdarg.h>

/**
 * struct GestionarFormato - Asocia un especificador con su función.
 * @especificador: Carácter del especificador (ej: 'd', 's').
 * @gestionador: Función que procesa el especificador.
 */
typedef struct GestionarFormato
{
	char especificador;
	void (*manejar)(va_list *, int *);
} GestionarFormato;


int _printf(const char *formato, ...);



#endif /* MI_PRINTF_H */
