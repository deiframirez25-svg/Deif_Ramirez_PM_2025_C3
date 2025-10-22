#include <stdio.h>
#include <string.h>
/* Calcula longitud.
El programa calcula la longitud de la cadena sin utilizar strlen. */

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

    int c = 0;
    while (cadena[c] != '\0')
        c++;
    return c;
}

