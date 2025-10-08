#include <stdio.h>
/* Arreglo sin elementos repetidos.
El programa, al recibir como dato un arreglo unidimensional desordenado de N
elementos, obtiene como salida ese mismo arreglo pero sin los elementos
repetidos. */
void Lectura(int *, int);
void Imprime(int *, int);
void Elimina(int *, int *);

void main(void)
{

    int TAM, ARRE[100];
    do
    {

        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    Lectura(ARRE, TAM);
    Elimina(ARRE, &TAM);
    Imprime(ARRE, TAM);
}

void Lectura(int A[], int T)
{

    printf("\n");
    int I;
    for (I = 0; I < T; I++)
    {

        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
{

    int I;
    printf("\nArreglo sin elementos repetidos:\n");
    for (I = 0; I < T; I++)
        printf("%d ", A[I]);
    printf("\n");
}

void Elimina(int A[], int *T)
{

    int I, J, K;
    for (I = 0; I < *T; I++)
    {

        for (J = I + 1; J < *T; )
        {

            if (A[I] == A[J])
            {

                for (K = J; K < *T - 1; K++)
                    A[K] = A[K + 1];
                (*T)--;
            }
            else                J++;
        }
    }
}

