#include <stdio.h>

void main(void)
{
    float ECA;
    printf("Ingresa la extension de la estacia: ");
    scanf("%f", &ECA);
    ECA = ECA * 4047 / 10000;
    printf("\nExtension de la estancia en hectareas: %5.2f", ECA);
}