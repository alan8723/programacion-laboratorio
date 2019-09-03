#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d\n", getIntRange("ingrese nota:", "Error reingrese nota ", 0, 10, 3, -1));

   // return 0;
}

int getIntRange(char*mensaje, char*mensajeError, int min, int max, int intentos, int retornoError)
{
    int numero;
    int contador = 1;
    int todoOk = 1;

    printf("%s", mensaje);
    scanf("%d", &numero);

    while(numero < min || numero > max){

    contador++;

    if(contador > intentos){

          printf("%d", retornoError);
          break;
    }
    else{
    printf("%s", mensajeError);
    scanf("%d", &numero);
    }



    }
    if(todoOk == 0){
        todoOk == retornoError;
    }
    else{
        todoOk = numero;
    }
    return todoOk;
};



