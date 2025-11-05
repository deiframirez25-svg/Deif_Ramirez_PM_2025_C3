#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[50];
    char carrera[50];
    float promedio;
} alumno;

void escribe(FILE *);

int main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL)
        escribe(ar);
    else        printf("\nEl archivo no se puede abrir");
    fclose(ar);
    return 0;
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0, r;
    printf("Deseas ingresar informacion sobre alumnos? (Si-1 / No-0): ");
    scanf("%d", &r);
    while (r)
    {

        i++;
        printf("\nDatos del alumno %d", i);

        printf("\nMatricula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        getchar();  // Limpia el salto de linea pendiente

        printf("Nombre del alumno %d: ", i);
        scanf(" %[^\n]", alu.nombre);

        printf("Carrera del alumno %d: ", i);
        scanf(" %[^\n]", alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);

        printf("\nDeseas ingresar mas informacion sobre alumnos? (Si-1 / No-0): ");
        scanf("%d", &r);
    }
    printf("\nDatos escritos correctamente.\n");
}



