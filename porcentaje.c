#include "_printf.h"
#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

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
