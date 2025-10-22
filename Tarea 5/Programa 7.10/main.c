#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Suma y promedio.
El programa recibe varias cadenas de caracteres que contienen numeros reales,
los suma y obtiene su promedio. */

int main(void)
{

    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    scanf(" %c", &c);

    while (c == 'S' || c == 's')
    {

        printf("\nIngrese la cadena de caracteres: ");
        scanf("%s", cad);

        i++;
        sum += atof(cad);

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        scanf(" %c", &c);
    }

    if (i > 0)
    {

        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f\n", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos.\n");
    }

    return 0;
}

