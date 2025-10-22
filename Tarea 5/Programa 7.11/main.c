#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Verifica si un caracter en una posicion especifica es una letra minuscula. */

int main(void)
{

    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (maximo 49): ");
    fgets(cad, sizeof(cad), stdin);

    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n')
    {
        cad[len - 1] = '\0';
    }

    printf("\nIngrese la posicion en la cadena que desea verificar: ");
    scanf("%d", &n);

    if (n >= 1 && n <= strlen(cad))
    {
        p = cad[n - 1];
        if (islower(p))
            printf("\n'%c' es una letra minuscula.\n", p);
        else            printf("\n'%c' no es una letra minuscula.\n", p);
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto.\n");
    }

    return 0;
}

