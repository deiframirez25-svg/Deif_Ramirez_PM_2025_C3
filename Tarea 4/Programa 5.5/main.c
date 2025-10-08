#include <stdio.h>
/* Frecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50
alumnos, obtiene la frecuencia de cada una de las calificaciones y ademas
escribe cual es la frecuencia mas alta. */
const int TAM = 50;

void Lectura(int VEC[], int T);
void Frecuencia(int VEC[], int T1, int FRE[], int T2);
void Impresion(int VEC[], int T);
void Mayor(int VEC[], int T);

void main(void)
{
    int CAL[TAM], FRE[6] = {0};
    Lectura(CAL, TAM);
    Frecuencia(CAL, TAM, FRE, 6);
    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);
    Mayor(FRE, 6);
}

void Lectura(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificacion -0:5- del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

void Frecuencia(int VEC[], int T1, int FRE[], int T2)
{
    int I;
    for (I = 0; I < T1; I++)
    {
        if (VEC[I] >= 0 && VEC[I] <= 5)
            FRE[VEC[I]]++;
    }
}

void Impresion(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nCalificacion %d: %d", I, VEC[I]);
}

void Mayor(int VEC[], int T)
{
    int I, MAY = VEC[0], IND = 0;
    for (I = 1; I < T; I++)
        if (VEC[I] > MAY)
        {
            MAY = VEC[I];
            IND = I;
        }
    printf("\n\nFrecuencia mas alta: %d (Calificacion %d)\n", MAY, IND);
}

