clude <stdio.h>
/* Ordenacion por insertacion directa. */
const int MAX = 100;

void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

void main(void)
{

    int TAM, VEC[MAX];
    do
    {

        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectur(VEC, TAM);
    rdena(VEC, TAM);
    Imprime(VEC, TAM);
}

void Lectura(int A[], int T)
{

    int I;
    for (I = 0; I < T; I++)
    {

        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Ordena(int A[], int T)
{

    int AUX, L, I;
    for (I = 1; I < T; I++)
    {

        AUX = A[I];
        L = I - 1;
        while ((L >= 0) && (AUX < A[L]))
        {

            A[L + 1] = A[L];
            L--;
        }
        A[L + 1] = AUX;
    }
}

void Imprime(int A[], int T)
{

    int I;
    for (I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}

