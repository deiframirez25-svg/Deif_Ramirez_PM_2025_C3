#include <stdio.h>

/* Mezcla.
   El programa mezcla, respetando el orden, dos archivos que se encuentran
      ordenados en forma ascendente considerando la matricula de los alumnos. */

void mezcla(FILE *, FILE *, FILE *);

void main(void)
{

    FILE *ar, *ar1, *ar2;
    ar = fopen("arc9.dat", "r");
    ar1 = fopen("arc10.dat", "r");
    ar2 = fopen("arc11.dat", "w");
    if (((ar != NULL) && (ar1 != NULL)) && (ar2 != NULL))
    {

        mezcla(ar, ar1, ar2);
        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else        printf("No se pueden abrir los archivos");
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
    int i, mat, mat1, b = 1, b1 = 1;
    float cal[3], cal1[3], cal_temp;
    int eof_ar = 0, eof_ar1 = 0;

    printf("Iniciando mezcla de archivos...\n");

    while (!eof_ar || !eof_ar1)
    {
        if (b && !eof_ar)
        {
            if (fscanf(ar, "%d", &mat) != 1)
            {
                eof_ar = 1;
            }
            else
            {
                for (i = 0; i < 3; i++)
                {
                    if (fscanf(ar, "%f", &cal[i]) != 1)
                    {
                        eof_ar = 1;
                        break;
                    }
                }
                if (!eof_ar)
                {
                    printf("Leido del archivo 1: %d %.2f %.2f %.2f\n", mat, cal[0], cal[1], cal[2]);
                    b = 0;
                }
            }
        }
        if (b1 && !eof_ar1)
        {
            if (fscanf(ar1, "%d", &mat1) != 1)
            {
                eof_ar1 = 1;
            }
            else
            {
                for (i = 0; i < 3; i++)
                {
                    if (fscanf(ar1, "%f", &cal1[i]) != 1)
                    {
                        eof_ar1 = 1;
                        break;
                    }
                }
                if (!eof_ar1)
                {
                    printf("Leido del archivo 2: %d %.2f %.2f %.2f\n", mat1, cal1[0], cal1[1], cal1[2]);
                    b1 = 0;
                }
            }
        }
        if (eof_ar && eof_ar1)
            break;
        if (eof_ar && !b1)
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%.2f\t", cal1[i]);
            fputs("\n", ar2);
            printf("Escrito: %d %.2f %.2f %.2f\n", mat1, cal1[0], cal1[1], cal1[2]);
            b1 = 1;
        }
        else if (eof_ar1 && !b)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%.2f\t", cal[i]);
            fputs("\n", ar2);
            printf("Escrito: %d %.2f %.2f %.2f\n", mat, cal[0], cal[1], cal[2]);
            b = 1;
        }
        else if (!b && !b1)
        {
            if (mat < mat1)
            {
                fprintf(ar2, "%d\t", mat);
                for (i = 0; i < 3; i++)
                    fprintf(ar2, "%.2f\t", cal[i]);
                fputs("\n", ar2);
                printf("Escrito: %d %.2f %.2f %.2f\n", mat, cal[0], cal[1], cal[2]);
                b = 1;
            }
            else
            {
                fprintf(ar2, "%d\t", mat1);
                for (i = 0; i < 3; i++)
                    fprintf(ar2, "%.2f\t", cal1[i]);
                fputs("\n", ar2);
                printf("Escrito: %d %.2f %.2f %.2f\n", mat1, cal1[0], cal1[1], cal1[2]);
                b1 = 1;
            }
        }
    }
    while (!eof_ar)
    {
        if (fscanf(ar, "%d", &mat) != 1)
        {
            eof_ar = 1;
            break;
        }
        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
        {
            if (fscanf(ar, "%f", &cal_temp) == 1)
                fprintf(ar2, "%.2f\t", cal_temp);
        }
        fputs("\n", ar2);
        printf("Escrito resto archivo 1: %d\n", mat);
    }
    while (!eof_ar1)
    {
        if (fscanf(ar1, "%d", &mat1) != 1)
        {
            eof_ar1 = 1;
            break;
        }
        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
        {
            if (fscanf(ar1, "%f", &cal_temp) == 1)
                fprintf(ar2, "%.2f\t", cal_temp);
        }
        fputs("\n", ar2);
        printf("Escrito resto archivo 2: %d\n", mat1);
    }
    fflush(ar2);
    printf("Mezcla completada.\n");
}



