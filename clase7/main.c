#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/*void obtenerAlumno(int, int, char, int, int, int, float);
void mostrarAlumnos(int[], int[], char[], int[], int[], float[], int);*/

int main()
{
    int legajo[TAM]={936, 458, 123, 448, 366};
    int edad[TAM]={21, 25, 27, 20, 19};
    char sexo[TAM]={'f', 'm', 'f', 'f', 'm'};
    int n1[TAM]={8, 5, 9, 10, 10};
    int n2[TAM]={7, 5, 6, 3, 9};
    float promedio[TAM] = {6.33, 5.33, 8, 6.66, 8};


    mostrarAlumnos(legajo, edad, sexo, n1, n2, promedio, TAM);
    return 0;
}


void mostrarAlumnos(int leg [], int edad[], char sex[], int n1[], int n2[], float promedio[], int tam){

    for (int i = 0; i < TAM; i++){
            obtenerAlumno(leg[i], edad[i], sex[i], n1[i], n2[i], n2[i], promedio[i]);
    }
}

void obtenerAlumno(int leg, int edad, char sex, int n1, int n2, float promedio){

    printf("%d\t %d\t %c\t %d\t %d\t %.2f \n",leg, edad, sex, n1, n2, promedio);

}
