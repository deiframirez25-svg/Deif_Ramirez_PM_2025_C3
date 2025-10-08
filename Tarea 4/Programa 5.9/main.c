#include <stdio.h>
/* Busqueda secuencial en arreglos desordenados. */
const int MAX = 100;

void Lectura(int[], int);
int Busca(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);
    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = Busca(VEC, TAM, ELE);
    if (RES)
        printf("\nEl elemento se encuentra en la posicion %d", RES);
    else        printf("\nEl elemento no se encuentra en el arreglo");
}

void Lectura(int A[], int T)
{
    int I;
    printf("\n");
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int E)
{
    int I;
    for (I = 0; I < T; I++)
        if (A[I] == E)
            return I + 1;
    return 0;
}

