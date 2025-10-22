#include <stdio.h>
#include <string.h>
/* Cadena invertida resuelta en forma recursiva. */
void inverso(char *);

int main(void)
{
    char fra[50];
    printf("\nIngrese la linea de caracteres: ");
    if (fgets(fra, sizeof(fra), stdin) == NULL)
    {
        printf("\nError al leer la entrada.\n");
        return 1;
    }
    fra[strcspn(fra, "\n")] = '\0';

    if (strlen(fra) == 0)
    {
        printf("\nLa cadena esta vacia.\n");
        return 1;
    }

    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
    printf("\n");
    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0')
    {
        inverso(cadena + 1);
        putchar(cadena[0]);
    }
}

