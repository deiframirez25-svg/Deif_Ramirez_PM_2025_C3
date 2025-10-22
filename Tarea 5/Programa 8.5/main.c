#include <stdio.h>
#include <string.h>
/* Uniones.
El programa muestra la manera como se declara una union, asi como la forma de
acceso a los campos de las variables de tipo union tanto para asignacion
de valores como para lectura y escritura. */

union datos
{
    char celular[15];
    char correo[20];
};

typedef streambuf
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
} alumno;

void Lectura(alumno *a);

int main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, .personales.celular = "5-158-40-50"};
    alumno a2, a3;

    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    while (getchar() != '\n');

    printf("Ingrese el nombre: ");
    if (fgets(a2.nombre, sizeof(a2.nombre), stdin) != NULL)
    {
        a2.nombre[strcspn(a2.nombre, "\n")] = '\0';
    }

    printf("Ingrese la carrera: ");
    if (fgets(a2.carrera, sizeof(a2.carrera), stdin) != NULL)
    {
        a2.carrera[strcspn(a2.carrera, "\n")] = '\0';
    }

    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    while (getchar() != '\n');

    printf("Ingrese el correo electronico: ");
    if (fgets(a2.personales.correo, sizeof(a2.personales.correo), stdin) != NULL)
    {
        a2.personales.correo[strcspn(a2.personales.correo, "\n")] = '\0';
    }
    printf("Alumno 3\n");
    Lectura(&a3);

    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);

    strcpy(a1.personales.correo, "hgimenez@hotmail.com");
    puts(a1.personales.celular);
    puts(a1.personales.correo);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular);
    puts(a2.personales.correo);

    printf("Ingrese el telefono celular del alumno 2: ");
    if (fgets(a2.personales.celular, sizeof(a2.personales.celular), stdin) != NULL)
    {
        a2.personales.celular[strcspn(a2.personales.celular, "\n")] = '\0';
    }
    puts(a2.personales.celular);
    puts(a2.personales.correo);

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo);

    return 0;
}

void Lectura(alumno *a)
{
    printf("\nIngrese la matricula: ");
    scanf("%d", &a->matricula);
    while (getchar() != '\n');

    printf("Ingrese el nombre: ");
    if (fgets(a->nombre, sizeof(a->nombre), stdin) != NULL)
    {
        a->nombre[strcspn(a->nombre, "\n")] = '\0';
    }

    printf("Ingrese la carrera: ");
    if (fgets(a->carrera, sizeof(a->carrera), stdin) != NULL)
    {
        a->carrera[strcspn(a->carrera, "\n")] = '\0';
    }
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    while (getchar() != '\n');

    printf("Ingrese el telefono celular: ");
    if (fgets(a->personales.celular, sizeof(a->personales.celular), stdin) != NULL)
    {
        a->personales.celular[strcspn(a->personales.celular, "\n")] = '\0';
    }
}


