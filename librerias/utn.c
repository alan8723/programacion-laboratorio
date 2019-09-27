#include "utn.h"
#include <stdio.h>

// \bryef pasa letra a mayuscula
// \param letra que pasará a amyuscula
// \return letra convertida

int letterUp(char letter){

    if(letter <= 'z' && letter >= 'a'){

     letter -= 32;
    }
    else{
        printf("error al ingresar caracter");
    }
    return letter;
}

// \bryef pasa letra a minuscula
// \param letra que pasará a minuscula
// \return letra convertida
int letterDown(char letter){

    if(letter <= 'Z' && letter >= 'A'){

     letter += 32;
    }
    else{
        printf("error al ingresar caracter");
    }
    return letter;
}
    //\brief Solicita numero al usuario
    //\param mensaje Es el mensaje a ser mostrado
    //\return numero ingresado por el usuario

int getInt(char mensaje[]){

    int auxiliar;

    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    return auxiliar;

}

    //\brief Solicita un caracter al usuario
    //\param mensaje Es el mensaje a ser mostrado
    //\return caracter ingresado por el usuario

char getChar(char mensaje[]){

    char auxiliar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);


    return auxiliar;

}

    //\brief Solicita numero con coma al usuario
    //\param mensaje Es el mensaje a ser mostrado
    //\return numero con coma ingresado por el usuario

float getFloat(char mensaje[]){

    float auxiliar;

    printf("%s", mensaje);
    scanf("%f", &auxiliar);


    return auxiliar;

}
