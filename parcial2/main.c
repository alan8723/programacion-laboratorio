#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "bicicleta.h"


int main()
{
    LinkedList* lista = ll_newLinkedList();

    int option = 0;

    char path[50];

    switch(menu()){
        case 1:
            printf("ingrese nombre de archivo: " &path);
            loadFromText(path, lista);
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:

        break;
        case 5:

        break;
        case 6:

        break;

    }

    return 0;
}
