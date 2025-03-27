#include "main.h"
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
