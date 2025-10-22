#include <stdio.h>
#include <string.h>
/* Declaracion de cadenas de caracteres y asignacion de valores. */
void main(void)
{
    char *cad0;
    cad0 = "Argentina";
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);

    char cad1[50];
    printf("\nIngrese una linea de texto -se lee con fgets-: \n");
    fgets(cad1, sizeof(cad1), stdin);
    cad1[strcspn(cad1, "\n")] = '\0';

    char cad2[20] = "Mexico";
    puts(cad2);

    printf("\nIngrese una linea de texto -se lee con fgets-: \n");
    fgets(cad2, sizeof(cad2), stdin);
    cad2[strcspn(cad2, "\n")] = '\0';
    puts(cad2);
}

