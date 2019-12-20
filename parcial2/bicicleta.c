#include "bicicleta.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eBicicleta* bici_new(){
eBicicleta* nuevo = (eBicicleta*) malloc( sizeof(eBicicleta));
    if( nuevo != NULL)
    {
        nuevo->idBike = 0;
        strcmp(nuevo->nombre, " ");
        strcpy(nuevo->tipo, " ");
        nuevo->tiempo = 0;
    }
    return nuevo;
}

eBicicleta* bici_newParam(char* idBike, char* nombre, char* tipo, char* tiempo){
    eBicicleta* nuevo = bici_new();
    if( nuevo != NULL)
    {
        if(
            bici_setIdBike(nuevo, atoi(idBike))
            && bici_setNombre(nuevo, nombre)
            && bici_setTipo(nuevo, tipo)
            && bici_setTiempo(nuevo, atoi(tiempo)) == 0)
        {
            free(nuevo);
            nuevo = NULL;
        }
    }
    return nuevo;
}

int bici_setIdBike(eBicicleta* this,int idBike)
{
    int todoOk=0;
    if( this != NULL)
    {
        this->idBike = idBike;
        todoOk = 1;
    }
    return todoOk;
}

int bici_getIdBike(eBicicleta* this,int* idBike)
{
    int todoOk=0;
    if( this != NULL && idBike != NULL)
    {
        strcpy( idBike, this->idBike);
        todoOk = 1;
    }
    return todoOk;
}

int bici_setNombre(eBicicleta* this,char* nombre){
    int todoOk=0;
    if( this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int bici_getNombre(eBicicleta* this,char* nombre){
    int todoOk=0;
    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int bici_setTipo(eBicicleta* this,char* tipo){
    int todoOk=0;
    if( this != NULL && tipo != NULL)
    {
        strcpy(this->tipo, tipo);
        todoOk = 1;
    }
    return todoOk;
}
int bici_getTipo(eBicicleta* this,char* tipo){
    int todoOk=0;
    if( this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        todoOk = 1;
    }
    return todoOk;
}

int bici_setTiempo(eBicicleta* this,int tiempo){
    int todoOk=0;
    if( this != NULL)
    {
        this->tiempo = tiempo;
        todoOk = 1;
    }
    return todoOk;
}
int bici_getTiempo(eBicicleta* this,int tiempo){
    int todoOk=0;
    if( this != NULL && tiempo != NULL)
    {
        strcpy( tiempo, this->tiempo);
        todoOk = 1;
    }
    return todoOk;
}

int loadFromText(char* path , LinkedList* biciList)
{
    FILE* f = NULL;
    int todoOk = 0;
    char buffer [5][30];
    eBicicleta* aux;
        if( biciList == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        return todoOk;
    }

    f = fopen(path, "r");
    if( f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return todoOk;
    }else {
        fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(f)){
                fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                aux = bici_newParam(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(biciList, aux);
        }
        todoOk = 1;
    }

    fclose(f);

    return todoOk;
}

void mostrarBici(eBicicleta* bici){

    printf("%d -- %s -- %s -- %d \n", bici->idBike, bici->nombre, bici->tipo, bici->tiempo);
}

int mostrarBicicletas(LinkedList* bicicletas)
{
    int todoOk = 0;

    if(bicicletas == NULL && ll_isEmpty(bicicletas))
    {
        printf("no hay nada para mostrar \n");
    }else
        {
        int tam = ll_len(bicicletas);

        for(int i=0; i < tam; i++){

            mostrarBici((eBicicleta*)ll_get(bicicletas, i));

        }

        todoOk = 1;
    }

    return todoOk;
}

float promedioVelocidad(LinkedList* bicis){
    int acumulador = 0;
    float resultado;
    eBicicleta* aux;
    for(int i = 0; i<ll_len(bicis); i++){
        aux = ll_get(bicis, i);
        acumulador += aux->tiempo;
    }
    resultado = (float) acumulador / ll_len(bicis);

    printf("el promedio es: %.2f \n", resultado);
    return resultado;
}

int menu(){

    int opcion;
    printf("1) CARGAR ARCHIVO \n");
    printf("2) IMPRIMIR LISTA \n");
    printf("3) CALCULAR VELOCIDAD PROMEDIO\n");
    printf("4) FILTRAR POR TIPO \n");
    printf("5) MOSTRAR POSICIONES \n");
    printf("6) SALIR \n");
    scanf("%d", &opcion);

    return opcion;
}
