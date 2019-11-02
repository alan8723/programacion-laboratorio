#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
    int id;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

int mostrarEmpleado(eEmpleado* unEmpleado);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo);
int inicializarEmpleados(eEmpleado* vec, int tam);

int main()
{
    //eEmpleado emp1;
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)* TAM);

    eEmpleado* emp2 = newEmpleado();

    if(inicializarEmpleados(lista, TAM)){
        printf("Empleados inicializar \n");
    }
    else{
        printf("No se pudo inicializar");
    }

    //formas de cargar datos
    /*emp2->id = 1212;
    printf("ingrese id: ");
    scanf("%d", &emp2->id );*/
    eEmpleado* emp3 = newEmpleadoParam(3322, "jose", 34000);

    mostrarEmpleado(emp3);
    return 0;
}

eEmpleado* newEmpleado(){
    eEmpleado* e;

    e = (eEmpleado*) malloc( sizeof(eEmpleado));

    if( e != NULL){
        e->id = 0;
        strcpy(e->nombre, "sin asignar");
        e->sueldo = 0;
        e->estado = 0;
    }

    return e;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo){
eEmpleado* e;

e = newEmpleado();

if( e != NULL){
    e->id = id;
    strcpy(e->nombre, nombre);
    e->sueldo = sueldo;
    e->estado = 0;
}
return e;

}

int mostrarEmpleado(eEmpleado* unEmpleado){

    int todoOk = 0;
    if(unEmpleado != NULL){
        printf("%d %s %.2f", unEmpleado->id, unEmpleado->nombre, unEmpleado->sueldo);

        todoOk = 1;
    }

    return todoOk;
}

int inicializarEmpleados(eEmpleado* vec, int tam){
    int todoOk = 0;
    if(vec != NULL && tam >=0){

        for(int i=0; i < tam; i++){

            (vec + i)->estado = 0;
        }
    todoOk = 1;
    }
    return todoOk;
}
