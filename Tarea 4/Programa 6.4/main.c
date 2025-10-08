#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
#include <stdio.h>
/* Simetrico.
El programa, al recibir como dato un arreglo bidimensional cuadrado, determina
si el mismo es simetrico. */

const int MAX = 100;

void Lectura(int [][MAX], int);
int Simetrico(int [][MAX], int);

int main(void)
{
    int MAT[MAX][MAX], N, RES;

    do
    {
        printf("Ingrese el tamano del arreglo (1 a %d): ", MAX);
        scanf("%d", &N);
    }
    while (N > MAX || N < 1);

    Lectura(MAT, N);
    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es simetrico.\n");
    else        printf("\nEl arreglo bidimensional no es simetrico.\n");

    return 0;
}

void Lectura(int A[][MAX], int T)
{

    int I, J;
    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++)
        {
            printf("Fila %d, Columna %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

int Simetrico(int A[][MAX], int T)
{

    int I = 0, J, F = 1;
    while ((I < T) && F)
    {
        J = 0;
        while ((J < I) && F)
        {
            if (A[I][J] == A[J][I])
                J++;
            else                F = 0;
        }
        I++;
    }
    return F;
}

