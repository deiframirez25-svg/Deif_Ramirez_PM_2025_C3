#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

int comparar(const void *a, const void *b)
{
    alumno *al1 = (alumno *)a;
    alumno *al2 = (alumno *)b;
    return al1->matricula - al2->matricula;
}

int main(void)
{
    FILE *ar1, *ar2;
    alumno *lista;
    int total, i;

    ar1 = fopen("ad5.dat", "rb");
    ar2 = fopen("ad6.dat", "wb");
    if (ar1 == NULL || ar2 == NULL)
    {
        printf("No se pudieron abrir los archivos.\n");
        return 1;
    }
    fseek(ar1, 0, SEEK_END);
    total = ftell(ar1) / sizeof(alumno);
    rewind(ar1);
    lista = (alumno *)malloc(total * sizeof(alumno));
    if (lista == NULL)
    {
        printf("No hay suficiente memoria.\n");
        fclose(ar1);
        fclose(ar2);
        return 1;
    }
    fread(lista, sizeof(alumno), total, ar1);
    qsort(lista, total, sizeof(alumno), comparar);
    for (i = 0; i < total; i++)
    {
        printf("Matricula: %d\n", lista[i].matricula);
        printf("Nombre: %s\n", lista[i].nombre);
        printf("Carrera: %d\n", lista[i].carrera);
        printf("Promedio: %.2f\n", lista[i].promedio);
        printf("---------------------------\n");
        fwrite(&lista[i], sizeof(alumno), 1, ar2);
    }
    free(lista);
    fclose(ar1);
    fclose(ar2);
    return 0;
}




