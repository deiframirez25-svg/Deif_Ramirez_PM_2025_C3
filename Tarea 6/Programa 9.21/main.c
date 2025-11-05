#include <stdio.h>

typedef struct
{
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);

int main(void)
{
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    ap = fopen("alu1.dat", "rb");
    c1 = fopen("car1.dat", "w+b");
    c2 = fopen("car2.dat", "w+b");
    c3 = fopen("car3.dat", "w+b");
    c4 = fopen("car4.dat", "w+b");
    c5 = fopen("car5.dat", "w+b");

    if ((ap != NULL) && (c1 != NULL) && (c2 != NULL) && (c3 != NULL) &&
            (c4 != NULL) && (c5 != NULL))
    {
        rewind(ap);  // Muy importante
        pro = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISION: %.2f", pro);

        rewind(ap);  // Rewind para que F2 lea desde el principio
        F2(ap, c1, c2, c3, c4, c5);

        F3(c1, c2, c3, c4, c5);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir");
    }
    fclose(ap);
    fclose(c1);
    fclose(c2);
    fclose(c3);
    fclose(c4);
    fclose(c5);

    return 0;
}

float F1(FILE *ap)
{
    alumno alu;
    float sum = 0;
    int i = 0;

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        sum += alu.examen;
        i++;
    }
    return (i > 0) ? sum / i : 0;
}

void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;
    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        if (((alu.examen >= 1300) && (alu.promedio >= 8)) ||
                ((alu.examen >= 1000) && (alu.promedio >= 7)))
        {
            switch (alu.carrera)
            {
            case 1:
                fwrite(&alu, sizeof(alumno), 1, c1);
                break;
            case 2:
                fwrite(&alu, sizeof(alumno), 1, c2);
                break;
            case 3:
                fwrite(&alu, sizeof(alumno), 1, c3);
                break;
            case 4:
                fwrite(&alu, sizeof(alumno), 1, c4);
                break;
            case 5:
                fwrite(&alu, sizeof(alumno), 1, c5);
                break;
            }
        }
    }
}

void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    FILE *files[5] = {c1, c2, c3, c4, c5};
    float cal[5] = {0};
    alumno alu;

    for (int i = 0; i < 5; i++)
    {
        int count = 0;
        float sum = 0;

        rewind(files[i]);

        while (fread(&alu, sizeof(alumno), 1, files[i]) == 1)
        {
            sum += alu.examen;
            count++;
        }
        cal[i] = (count > 0) ? sum / count : 0;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
    }
}



