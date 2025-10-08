#include <stdio.h>
/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 numeros
primos. */
const int TAM = 100;

void Imprime(int Primos[], int T);
void Primo(int A, int *B);

void main(void)
{
    int P[TAM];
    int FLA, J = 2, PRI = 3;
    P[0] = 1;
    P[1] = 2;
    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);
        if (FLA)
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);
}

void Primo(int A, int *B)
{
    int DI = 3;
    while (*B && (DI <= (A / 2)))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
    }
}

void Imprime(int Primos[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}

