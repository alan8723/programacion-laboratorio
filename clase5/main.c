#include <stdio.h>
#include <stdlib.h>

int main()
{

    void imprimirVector (int vec[], int tam){

    for(int i = 0; i < tam; i++){
        printf("%d \n\n", vec[i]);
    }
}

    int obtenerMayor(int vec[], int tam) {

        int max;

        for(int i=0; i < tam; i++){

            if(i==0){
                max = vec[i];
                //ubicacion = i;

            }
            if(vec[i] > max ){
                max = vec[i];
                //ubicacion = i;
            }
    }

    return max;
    }


    int acumulador=0;
    int numero[5];
    int max;
    int ubicacion;


    for (int i=0; i < 5; i++){
        printf("ingrese un numero: ");
        scanf("%d", &numero[i]);
    }

    imprimirVector(numero, 5);
    max = obtenerMayor(numero, 5);


    printf("la suma de tosod los numeros es %d,\n el numero maximo es %d,\n y su ubicacion es %d ", acumulador, max, ubicacion);
    return 0;

    /*for (int i=0; i < 5; i++){
        printf("%d \n", numero[i]);
    }*/
    /*for(int i=0; i < 5; i++){

            if(i==0){
                max = numero[i];
                ubicacion = i;

            }
            if(numero[i] > max ){
                max = numero[i];
                ubicacion = i;
            }


        acumulador += numero[i];
    }*/

}
