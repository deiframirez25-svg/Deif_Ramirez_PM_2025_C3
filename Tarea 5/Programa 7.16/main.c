#include <stdio.h>
#include <string.h>
/* Cuenta cadenas.
El programa, al recibir dos cadenas de caracteres, calcula e imprime cuantas
veces se encuentra la segunda cadena en la primera. */

int main(void)
{

    char cad1[50], cad2[50], cad0[50];
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);
    cad1[strcspn(cad1, "\n")] = '\0';

    printf("\nIngrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin);
    cad2[strcspn(cad2, "\n")] = '\0';

    if (strlen(cad2) == 0)
    {
        printf("\nLa cadena a buscar esta vacia.\n");
        return 1;
    }

    strcpy(cad0, cad1);
    char *ptr = cad0;
    ptr = strstr(ptr, cad2);

    while (ptr != NULL)
    {

        i++;
        ptr = strstr(ptr + 1, cad2);
    }

    printf("\nEl numero de veces que aparece la segunda cadena es: %d\n", i);
    return 0;
}

