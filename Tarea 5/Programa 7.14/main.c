#include <stdio.h>
#include <string.h>
/* Calcula longitud en forma recursiva.
El programa calcula de manera recursiva la longitud de la cadena
sin utilizar la funcion strlen. */

int cuenta(char *);

int main(void)
{

    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n')
    {
        cad[len - 1] = '\0';
    }

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d\n", i);

    return 0;
}

int cuenta(char *cadena)
{

    if (cadena[0] == '\0')
        return 0;
    else        return 1 + cuenta(&cadena[1]);
}

