#ifndef GESTIONAR_H
#define GESTIONAR_H

#include <stdarg.h>


void gestionar_caracter(va_list *args, int *contador);
void gestionar_cadena(va_list *args, int *contador);
void gestionar_entero(va_list *args, int *contador);
void gestionar_porcentaje(int *contador);
void gestionar_invalido(char caracter_invalido, int *contador);
int _putchar(char c);
#endif /* GESTIONAR_H */
