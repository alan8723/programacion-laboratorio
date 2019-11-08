#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "autos.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int ordenarAutosId(void* a1, void* a2);
int mostrarAutosll(LinkedList* lista);

int main()
{

    LinkedList* listaAutos = ll_newLinkedList();

    eAuto* auto1 = newAutoParam( 1000, "ford", 2009, 1000);
    eAuto* auto2 = newAutoParam( 1001, "fiat", 2012, 1200);
    eAuto* auto3 = newAutoParam( 1002, "peugeot", 2009, 900);
    eAuto* auto4 = newAutoParam( 1003, "renaut", 2015, 800);
    eAuto* auto5 = newAutoParam( 1004, "honda", 2009, 1100);

    eAuto* auxAuto = newAuto();

    ll_add(listaAutos, auto1);
    ll_add(listaAutos, auto2);
    ll_add(listaAutos, auto3);
    ll_add(listaAutos, auto4);
    ll_add(listaAutos, auto5);



    auxAuto = (eAuto*) ll_pop(listaAutos, auto2->id - 1000);

    mostrarAutosll(listaAutos);

    auxAuto->modelo = 2019;
    printf("\n");

    ll_push(listaAutos, 1, auxAuto);

    mostrarAutosll(listaAutos);

    //mostrarAuto((eAuto*) ll_get(listaAutos, 0));


    //printf("\n");

    //printf("%d\n", ll_len(listaAutos));

    //ll_sort(listaAutos, ordenarAutosId, 0);

    //mostrarAutosll(listaAutos);



    /*int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;*/


}

int mostrarAutosll(LinkedList* lista){

    int todoOk = -1;

    if(lista != NULL){
        int tam = ll_len(lista);

        for(int i=0; i < tam ; i++){
            mostrarAuto((eAuto*)ll_get(lista, i));
        }

        todoOk = 0;
    }

    return todoOk;
}

int ordenarAutosId(void* a1, void* a2){

    int rta = 0;

    eAuto* auto1 = (eAuto*) a1;
    eAuto* auto2 = (eAuto*) a2;

    if (auto1->id > auto2->id){
        rta = 1;
    }else if(auto1->id < auto2->id){
        rta = -1;
        }

    return rta;
}
