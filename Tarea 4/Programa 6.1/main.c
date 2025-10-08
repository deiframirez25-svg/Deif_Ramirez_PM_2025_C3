#include <stdio.h>

/* Diagonal principal.
El programa, al recibir como dato una matriz de tipo entero, escribe la
diagonal principal. */

const int TAM = 10;

void Lectura(int [][TAM], int);
void Imprime(int [][TAM], int);

int main(void)
{
    int MAT[TAM][TAM];
    Lectura(MAT, TAM);
    Imprime(MAT, TAM);
    return 0;
}

void Lectura(int A[][TAM], int F)
{

    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < F; J++)
        {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

void Imprime(int A[][TAM], int F)
{

    int I;
    for (I = 0; I < F; I++)
    {
        printf("Diagonal [%d][%d]: %d\n", I, I, A[I][I]);
    }
}

