#include <stdio.h>
#include <string.h>
/* Prototipo de funcion. */
void intercambia(char FRA[][30], int);

int main(void)
{
    int i, n;
    char FRA[20][30];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("\nNumero de filas invalido. Debe estar entre 1 y 20.\n");
        return 1;
    }

    while (getchar() != '\n');

    for (i = 0; i < n; i++)
    {
        printf("\nIngrese la linea de texto numero %d: ", i + 1);
        if (fgets(FRA[i], sizeof(FRA[i]), stdin) == NULL)
        {
            printf("\nError al leer la entrada.\n");
            return 1;
        }
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }
    printf("\n\n");
    intercambia(FRA, n);
    for (i = 0; i < n; i++)
    {
        printf("\nImpresion de la linea de texto %d: ", i + 1);
        puts(FRA[i]);
    }
    printf("\n");
    return 0;
}

void intercambia(char FRA[][30], int n)
{
    int i, j;
    char cad[30];
    for (i = 0; i < (n / 2); i++)
    {
        j = n - 1 - i;
        strcpy(cad, FRA[i]);
        strcpy(FRA[i], FRA[j]);
        strcpy(FRA[j], cad);
    }
}

