#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Cuenta letras minusculas y mayusculas en una cadena de caracteres. */

int main(void)
{

    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("\nIngrese la cadena de caracteres (maximo 49 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    size_t len = strlen(cad);
    if (len > 0 && cad[len - 1] == '\n')
    {
        cad[len - 1] = '\0';
    }

    while (cad[i] != '\0')
    {

        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }

    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d\n", ma);

    return 0;
}

