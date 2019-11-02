#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[30];
    char apellido[30];
    float sueldo;

}eEmpleado;

eEmpleado* newEmpleado();

int main()
{
    eEmpleado* lista[50];
    eEmpleado* emple = newEmpleado();
    int i=0;

    FILE* miArchivo;
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[10];
    char line[100];
    int primero = 0;

    miArchivo = fopen("datos.csv", "r");

    fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n],\n", legajo, nombre, apellido, sueldo);
    printf("%s---%s---%s---%s \n", emple->legajo, emple->nombre, emple->apellido, emple->sueldo);

    while(!feof(miArchivo)){

    /*if(primero == 0){
     fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n],\n", legajo, nombre, apellido, sueldo);
     primero = 1;
    }*/

    emple = newEmpleado();

    fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n],\n", legajo, nombre, apellido, sueldo);

    emple->legajo = atoi(legajo);

    strcpy(emple->nombre, nombre);

    strcpy(emple->apellido, apellido);

    emple->sueldo = atof(sueldo);

    *(lista+i) = emple;

    i++;
    }

    fclose(miArchivo);

    for(int i = 0; i <50; i++){
        printf("%d---%s---%s---%f \n", emple->legajo, emple->nombre, emple->apellido, emple->sueldo);
    }

        return 0;
}


eEmpleado* newEmpleado(){

    eEmpleado* e;

    e = (eEmpleado*) malloc(sizeof(eEmpleado));

    return e;

}
