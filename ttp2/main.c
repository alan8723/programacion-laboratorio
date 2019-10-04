#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define ELEMENTS 1

int main()
{
    Employee list[ELEMENTS]={0, 'alan', 'paez', 23000, 1, 1};
    char salir = 'n';
    int ultimoId = 000;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int todoOk;
    int indice;

    initEmployees(list, ELEMENTS);

   do{ switch(menu()){

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

            if (todoOk == -1){
                printf("ocurrio un error en el alta");
            }
            else{
                printf("Alta exitosa!!");
                ultimoId ++;
            }

            break;
        case 2:
            printf("opcion 2\n");
            break;
        case 3:
            printf("opcion 3\n");
            break;
        case 4:
            printf("opcion 4\n");
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
