#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char marca[30];
int modelo;
float precio;
}eAuto;
//nuevosAlumnos
eAuto* newAuto();
eAuto* newAutoParam(int id, char marca[30], int modelo, float precio);
//mostrar
int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** unAuto, int tam);
//seter
int setIdAuto(eAuto* unAuto, int id);
int setMarcaAuto(eAuto* unAuto, char *marca);
int setModeloAuto(eAuto* unAuto, int modelo);
int setPrecioAuto(eAuto* unAuto, float precio);
//geter
int getIdAuto(eAuto* unAuto);
int getMarcaAuto(eAuto* unAuto, char *marca);
int getModeloAuto(eAuto* unAuto);
float getPrecioAuto(eAuto* unAuto);
//escritita\\lectura//archivo
int guardarAutosBinario(eAuto** lista, int tam, char* path);

int main()
{
    int tam = 0;
    int cant = 0;
    char buffer[4][30];

    FILE* f = NULL;
    eAuto* auxAuto = NULL;
    eAuto** auxLista= NULL;
    eAuto** lista = (eAuto**) malloc(sizeof(eAuto*));

    if(lista == NULL){
        printf("no se pudo conseguir memoria");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f = fopen("autos.csv", "r");
    if(f== NULL){

        printf("no se pudo abrir el erchivo");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2] ,buffer[3]);


    while(!feof(f)){
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2] ,buffer[3]);

        if(cant < 4){
            break;
        }else{

                auxAuto = newAutoParam(atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));
                if (auxAuto != NULL){
                    *(lista + tam) = auxAuto;
                    tam++;

                    auxLista = (eAuto**) realloc(lista, sizeof(eAuto*) *(tam + 1));
                    if(auxLista != NULL){
                        lista = auxLista;
                    }

                }
        }
    }
    fclose(f);

    mostrarAutos(lista, tam);

    if(guardarAutosBinario(lista, tam, "autos.bin")){
        printf("autos guardados en archivo binario\n");
    }else{
        printf("no se pudieron guardar los datos");
    }


    //printf("Hello world!\n");
    return 0;
}

int setIdAuto(eAuto* unAuto, int id){

    int todoOk= 0;
    if(unAuto != NULL && id >= 1000 && id<= 100){

        unAuto->id = id;
        todoOk = 1;
    }


    return todoOk;

}

int getIdAuto(eAuto* unAuto){

    int id = -1;
    if(unAuto != NULL){

        id = unAuto->id;
    }


    return id;

}

int setMarcaAuto(eAuto* unAuto, char *marca){

     int todoOk= 0;
     if(unAuto != NULL && marca != NULL && strlen(marca) >=3){
        strcmp(unAuto->marca, marca);
        todoOk = 1;
     }

    return todoOk;
}

int getMarcaAuto(eAuto* unAuto, char *marca){
    int todoOk =0;

    if(unAuto != NULL && marca != NULL){
        strcmp(marca, unAuto->marca);
        todoOk = 1;
     }
     return todoOk;
}

int setModeloAuto(eAuto* unAuto, int modelo ){

    int todoOk = 0;
     if(unAuto != NULL && modelo > 1992 && modelo < 2011){
        unAuto->modelo = modelo;
        todoOk = 1;
     }

    return todoOk;
}

int getModeloAuto(eAuto* unAuto){
    int modelo = -1;

     if(unAuto != NULL){
        modelo = unAuto->modelo;

     }

    return modelo;
}

int setPrecioAuto(eAuto* unAuto, float precio){

    int todoOk = 0;
     if(unAuto != NULL && precio > 650.78 && precio < 1439.95){
        unAuto->precio = precio;
        todoOk = 1;
     }

    return todoOk;
}

float getPrecioAuto(eAuto* unAuto){

    float precio;
     if(unAuto != NULL){
        unAuto->precio = precio;

     }

    return precio;
}


int mostrarAuto(eAuto* unAuto){
    int todoOk = 0;

    if(unAuto != NULL){
        printf(" %d %20s %d %6.2f \n", unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio );
        todoOk = 1;
    }

    return todoOk;
}

int mostrarAutos(eAuto** unAuto, int tam){

    int todoOk=0;
    if (unAuto != NULL && tam > 0){

        for(int i = 0; i < tam; i++){
        mostrarAuto(*(unAuto + i));
        }

        todoOk = 1;
    }

    return todoOk;
}


eAuto* newAuto(){
eAuto* a;

    a = (eAuto*) malloc( sizeof(eAuto));

    if( a != NULL){
        a->id = 0;
        strcpy(a->marca, "sin asignar");
        a->modelo = 0;
        a->precio = 0;
    }

    return a;
}

eAuto* newAutoParam(int id, char marca[30], int modelo, float precio){

    eAuto* a;

    a = newAuto();

    if( a != NULL){
            if(
                ( setIdAuto(a, id)
                &&setModeloAuto(a, modelo)
                &&setMarcaAuto(a, marca)
                &&setPrecioAuto(a, precio)) == 0)
                {
                free(a);
                a=NULL;
                }

        /*a->id = id;
        strcpy(a->marca, marca);
        a->modelo = modelo;
        a->precio = precio;*/
    }
    return a;
}

int guardarAutosBinario(eAuto** lista, int tam, char* path){

    int todoOk = 0;
    FILE* f = NULL;

    if(lista != NULL && tam > 0 && path != NULL){

    f = fopen("autosBinario.bon", "wb");
    if(f== NULL){
        printf("no se pudo abrir el erchivo");
        system("pause");
        return todoOk;
    }

    for(int i = 0; i < tam; i++){
        fwrite( *(lista + i),  sizeof(eAuto), 1, f);
    }

    fclose(f);
    todoOk = 1;

    return todoOk;

    }
}
