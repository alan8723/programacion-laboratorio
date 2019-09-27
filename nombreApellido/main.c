#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMN 20
#define TAMNP 39

//obtenerNombre(vec[], tam)
void MostrarNombreYApellido(char[], char[], int);
//int letterUp(char);

int main()
{
    int flag=0;
    int i;
    int j=0;
    char nombre [TAMN]={0};
    char apellido [TAMN]={0};

    char nombreApellido[TAMNP]={0};

    printf("ingrece el nombre: ");
    scanf("%s", nombre);

    printf("ingrece el apellido: ");
    fflush(stdin);
    scanf("%s", apellido);

    MostrarNombreYApellido(nombre, apellido, TAMNP);


    return 0;
}

void MostrarNombreYApellido(char nombre[], char apellido[], int tamCom){


    char nombreApellido[TAMNP]={0};
    int flag=0;
    int i;
    int j=0;

    nombre[0] = letterUp(nombre[0]);
    apellido[0] = letterUp(apellido[0]);

    strcpy(nombreApellido, apellido);

     for(i=0; i < tamCom; i++){
        if(nombreApellido[i] == 0 && nombre[j] != 0){

            if(flag == 0){
                nombreApellido[i] = ' ';
                flag=1;
                i++;
            }
        nombreApellido[i] = nombre[j];
        j++;

        }
    }


    printf("%s", nombreApellido);
}
void letterUp(char letter){

    if(letter <= 'z' && letter >= 'a'){

     letter -= 32;
    }
    else{
        printf("error al ingresar caracter");
    }
    return letter;
}
