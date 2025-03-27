#ifndef GESTIONAR_H
#define GESTIONAR_H

#include <stdarg.h>


void gestionar_caracter(va_list *args, int *contador);
void gestionar_cadena(va_list *args, int *contador);
void gestionar_porcentaje(va_list *args, int *contador);
void gestionar_invalido(char caracter_invalido, int *contador);
int _putchar(char c);
int _printf(const char *formato, ...);

#endif /* GESTIONAR_H */
