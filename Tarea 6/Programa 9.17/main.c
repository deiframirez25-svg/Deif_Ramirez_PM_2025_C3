#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Reemplaza palabras.
   El programa lee cadenas de caracteres de un archivo y cada que vez queue   encuentra la palabra Mexico escrita en forma incorrecta la primera condicional
      minuscula la reemplaza por su forma correcta y escribe la cadena en otro
         archivo. */

void cambia(FILE *, FILE *);

void main(void)
{
    FILE *ar;
    FILE *ap;
    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");
    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else        printf("No se pueden abrir los archivos");
}

void cambia(FILE *ap1, FILE *ap2)
{
    char cad[30], *cad2;
    while (!feof(ap1))
    {
        fgets(cad, 30, ap1);
        cad2 = strstr(cad, "mexico");
        while (cad2 != NULL)
        {
            cad2[0] = 'M';
            cad2 = strstr(cad2 + 1, "mexico");
        }
        fputs(cad, ap2);
    }
}




