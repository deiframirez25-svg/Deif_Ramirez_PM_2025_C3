#include <stdio.h>
void main(void)
{
float Pro;
printf("Ingrese el promedio del alumno: ");
scanf("%f", &Pro);
if (Pro >= 6.0)
printf("\nAprobado");
else
printf("\nReprobado");
}