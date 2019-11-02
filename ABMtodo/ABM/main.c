#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 2
#include "Alumno.h"

int buscarLibre(eAlumno vec[], int tam);

int main()
{
    eAlumno alumnos[TAM];


   //do{


    switch(menu()){

    case 1:
        darDeAltaAlumno(alumnos, TAM);
        break;
    case 2:
        printf("Baja alumno \n\n");
        break;
    case 3:
        printf("Modificar alumno \n\n");
        break;
    case 4:
        printf("Listar alumno \n\n");
        break;
    case 5:
        printf("Ordenar alumno \n\n");
        break;
    case 6:
        printf("Informes alumno \n\n");
        break;
    case 7:
        printf("salir \n\n");

        break;
    default:
        printf("opccion invalida \n\n");
    }
  // }
    return 0;
}

int menu() {

    int option;

    system("cls");
    printf("****** ABM Alumnos ******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumno\n");
    printf("5-Ordenar alumno\n");
    printf("6-Informes alumno\n");
    printf("7-Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);

    scanf("%d", &option);

    return option;

}


int buscarLibre(eAlumno vec[], int tam){

    int indice = -1;

    for(int i=0; i < tam; i++){
            if(vec[i].libre){
                indice = i;
            };

    }

    return indice;

}


int inicializarAulumno(int legajo, eAlumno vec[], int tam){
    int indice = -1;

    for (int i=0; i < tam; i++){
            if(vec[i].libre == 1 && vec[i].legajo == legajo){
                indice = i;
                break;
            };
    }

    return indice;
}

int darDeAltaAlumno(eAlumno vec[], int tam){

    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    char nombre[29];
    float promedio;
    int libre;

    indice = buscarLibre(vec, TAM);

    if(indice == -1){

            printf("\n No se pueden ingresar mas alumnos \n");

    }
    else{
            printf("incgrece legajo: ");
            scanf("%d", legajo);

            esta = inicializarAulumno(legajo, vec, TAM);
            if (esta != -1){

                mostrarUnAlumno(vec[esta]);


            }
            else{
                printf("ingrese nombre: ");
                fflush(stdin);
                scanf("%s", vec[indice].nombre);

                printf("ingrese promedio: ");
                fflush(stdin);
                scanf("%f", &promedio);
            }



    }


}

void mostrarUnAlumno(eAlumno miAlumno)
{

    printf("%d--%s--%f",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio);

}




