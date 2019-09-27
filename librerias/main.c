#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char letra;
    letra = getChar("ingrece una letra \n");

    letra = letterUp(letra);

    printf("la letra ingresada es: %c \n", letra );

    return 0;
}




