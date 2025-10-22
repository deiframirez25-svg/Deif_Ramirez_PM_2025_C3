#include <stdio.h>
#include <ctype.h>
/* Descodifica.
El programa descodifica una cadena de caracteres compuesta por numeros y letras. */

void interpreta(char *);

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    for (int i = 0; cad[i] != '\0'; i++)
    {
        if (cad[i] == '\n')
        {
            cad[i] = '\0';
            break;
        }
    }
    interpreta(cad);
    printf("\n");
    return 0;
}

void interpreta(char *cadena)
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))
        {
            if (i > 0 && isdigit(cadena[i - 1]))
            {
                k = cadena[i - 1] - '0';
                for (j = 0; j < k; j++)
                    putchar(cadena[i]);
            }
        }
        i++;
    }
}

