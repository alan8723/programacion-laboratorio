#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define ELEMENTS 10

int main()
{
    Employee list[ELEMENTS]/*={{0, "alan", "paez", 23000, 1, 0},{1, "pepe", "titolo", 24000, 2, 0}, {2, "juana", "lozano", 28000, 2, 0}, {3, "maxi", "lopez", 18000, 3, 0}}*/;

    char salir = 'n';
    int ultimoId = 000;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int todoOk;
    int indice;
    int id;
    int opcion;

    initEmployees(list, ELEMENTS);

        do{

        switch(menu()){

        case 1:

            printf("****** ALTA DE NUEVO EMPLEADO ****** \n\n");

            printf("ingrese el nombre del empleado: \n");
            fflush(stdin);
            scanf("%s", &name);

            printf("ingrese el apellido del empleado: \n");
            fflush(stdin);
            scanf("%s", &lastName);

            printf("ingrese salario del empleado: \n");
            fflush(stdin);
            scanf("%f", &salary);

            printf("ingrese sector del empleado: \n");

            scanf("%d", &sector);

            todoOk = addEmployees(list, ELEMENTS, ultimoId, name, lastName, salary, sector);

            if(todoOk){
                ultimoId++;
            }

            break;
        case 2:
            modificarEmployee(list, ELEMENTS);
            break;
        case 3:
            printf("ingrse id: ");
            scanf("%d", &id);
            removeEmployee(list, ELEMENTS, id);
            break;
        case 4:
            printEmployees(list, ELEMENTS);
            break;
        case 5:
            printf("cancelar salir 'n' confirmar ingrese cualquier otra letra.\n");
            fflush(stdin);
            salir = getche();
            break;
        default:
            printf("error al ingresar opcion");
    }
    system("pause");
    system("cls");
    }
    while(salir == 'n');

    return 0;


}


