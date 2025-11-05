#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[50];
    char carrera[50];   // <- corregido: cadena, no int    float promedio;
} alumno;

void lee(FILE *);

int main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "rb")) != NULL)
    {
        lee(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }
    return 0;
}

void lee(FILE *ap)
{
    alumno alu;
    int num = 1;

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        printf("\nAlumno %d:", num++);
        printf("\nMatricula: %d", alu.matricula);
        printf("\nNombre: %s", alu.nombre);
        printf("\nCarrera: %s", alu.carrera);
        printf("\nPromedio: %.2f\n", alu.promed
