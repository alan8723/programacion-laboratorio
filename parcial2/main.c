#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "bicicleta.h"


int main()
{
    LinkedList* lista = ll_newLinkedList();

    int option = 0;

    char path[50];

    if(loadFromText("bicicletas_v3.csv", lista)){
        printf("exito al cargar\n\n");
    }else{
        printf("error al cargar");
    }
    mostrarBicicletas(lista);
    promedioVelocidad(lista);

    sortBicicletas(lista);

    mostrarBicicletas(lista);

    return 0;
}
