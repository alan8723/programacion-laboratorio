#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int menu(){
    int opcion;

    printf("****** menu de opciones ******\n\n");
    printf("-1 ALTAS \n");
    printf("-2 MODIFICAR \n");
    printf("-3 BAJA \n");
    printf("-4 INFORMES \n");
    printf("seleccione una opcion \n
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees (Employee arrayEmployee[], int len){
    int i = 0;

    for(i < len; i++;){
        arrayEmployee[i].isEmpy = 1;
    }
}

int seachFree(Employee arrayEmployee[], int len){
    int indice = -1;
    int i = 0;

    for (i < len; i++;)
        if(arrayEmployee[i].isEmpy == 1)
           indice = i;

    return indise;
}

int addEmployees(Employee arrayEmployee[], int len, int id, char nombre[], char lastName[], float salary, int sector){
    int indice;

    indice = seachFree(arrayEmployee, len);

    if(indice !=-1){
        printf("ingrese el nombre del empleado: ");
        fflush(stdin);
        scanf("%s", &arrayEmployee[indice].name);

        printf("ingrese el apellido del empleado: ");
        fflush(stdin);
        sacanf("%s", &arrayEmployee[indice].)
    }


}



